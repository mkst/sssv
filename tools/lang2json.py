"""Work-in-progress reimagination of tc.exe

langX.dat format

- Header contains the offsets (u32) to each Section
- Section starts with the number of messages (u16) followed by the message
  - Message starts with a message length (u16), and ends with 0x7530
- Section ends with some unknown(*) padding to 16-byte boundary

(*) TODO: determine whether padding is junk or leftover data or what.

Language order is:
    AMERICAN (unused)
    DUTCH
    ENGLISH
    FRENCH
    GERMAN
    ITALIAN
    JAPANESE
    PORTUGESE
    SPANISH
"""

import argparse
import struct
import json


# TILESET NOTES:
# (1) £ is a dupe of 物 and IS used (twice)
# (2) $ is a dupe of À and IS used (once)
# (3) _ is a dupe of ù but is unused
# (4) ^ is a dupe of ひ and IS used (once)
# (5) & is a dupe of な and IS used (once)

# 336 (@) control character (empty tile in tileset image)
# 307 (#) control character (tile exists but is unused in dialogue)

# huge thanks to Wedarobi + PeterFoxSNS + blu for identifying the majority of Japanese characters!
tileset = [
    'あ', 'い', 'う', 'え', 'お', 'か', 'き', 'く', 'け', 'こ', 'さ', 'し', 'す', 'せ', 'そ', 'た',
    'ち', 'つ', 'て', 'と', 'な', 'に', 'ぬ', 'ね', 'の', 'は', 'ひ', 'ふ', 'へ', 'ほ', 'ま', 'み',
    'む', 'め', 'も', 'や', 'ゆ', 'よ', 'ら', 'り', 'る', 'れ', 'ろ', 'わ', 'を', 'ん', 'が', 'ぎ',
    'ぐ', 'げ', 'ご', 'ざ', 'じ', 'ず', 'ぜ', 'ぞ', 'だ', 'ぢ', 'づ', 'で', 'ど', 'ば', 'び', 'ぶ',
    'べ', 'ぼ', 'ぱ', 'ぴ', 'ぷ', 'ぺ', 'ぽ', 'ア', 'イ', 'ウ', 'エ', 'オ', 'カ', 'キ', 'ク', 'ケ',
    'コ', 'サ', 'シ', 'ス', 'セ', 'ソ', 'タ', 'チ', 'ツ', 'テ', 'ト', 'ナ', 'ニ', 'ヌ', 'ネ', 'ノ',
    'ハ', 'ヒ', 'フ', 'ヘ', 'ホ', 'マ', 'ミ', 'ム', 'メ', 'モ', 'ヤ', 'ユ', 'ヨ', 'ラ', 'リ', 'ル',
    'レ', 'ロ', 'ワ', 'ヲ', 'ン', 'ガ', 'ギ', 'グ', 'ゲ', 'ゴ', 'ザ', 'ジ', 'ズ', 'ゼ', 'ゾ', 'ダ',
    'ヂ', 'ヅ', 'デ', 'ド', 'パ', 'ピ', 'プ', 'ペ', 'ポ', 'ぁ', 'ぃ', 'ぅ', 'ぇ', 'ぉ', 'ゃ', 'ゅ',
    'ょ', 'っ', 'ァ', 'ィ', 'ゥ', 'ェ', 'ォ', 'ャ', 'ュ', 'ョ', 'ッ', '。', '、', '？', '！', 'ー',
    '「', '」', '＜', '＞', '＆', '／', '・', 'バ', 'ビ', 'ブ', 'ベ', 'ボ', '天', '才', '分', '急',
    '攻', '撃', '爆', '破', '救', '出', '乗', '運', '行', '島', '建', '£', '博', '士', '戦', '車',  # (1)
    '飛', '機', '発', '見', '南', '極', '魔', '王', '日', '本', '壊', '水', '前', '後', '病', '院',
    '死', '全', '自', '動', '遂', '工', '場', '沈', '船', '客', '火', '山', '案', '内', '燃', '料',
    '逃', '亡', '所', '守', '輸', '送', '武', '器', '庫', '安', '現', '銃', '弾', '時', '間', '…',
    '歩', '兵', '正', '村', '防', '使', '敵', '変', '異', '学', '校', '教', '団', '子', '供', '調',
    '$', 'Â', 'Ç', 'É', 'È', 'Ê', 'Ï', 'Î', 'Ô', 'Ù', 'Ü', 'Ú', 'Æ', 'Ä', 'Ö', '_',   # (2), (3)
    'à', 'â', 'ç', 'é', 'è', 'ê', 'ï', 'î', 'ô', 'û', 'ü', 'ú', 'æ', 'ä', 'ö', 'ß',
    '¡', '¿', 'Ó', 'á', 'ñ', 'Ñ', 'ã', 'Ã', 'õ', 'Õ', 'í', 'ó', 'ù', 'À', 'ì', '一',
    ' ', '!', '"', '#', '犬', '岩', 'ò', "'", '生', '砂', '—', '巨', ',', '-', '.', '大',
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', '滅', '‒', '絶', '|', '?',
    '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O',
    'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '♫', '🔊', '☑️', '☐', 'Í',
    '物', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o',
    'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'ヴ', '^', '口', '&', '笑',  # (4), (5)
]
# slightly faster than index()-ing a list...
tileset_dict = dict(zip(tileset, range(len(tileset))))


def read_short(fhandle):
    res, = struct.unpack('>h', fhandle.read(2))
    return res


def read_word(fhandle):
    res, = struct.unpack('>i', fhandle.read(4))
    return res


def peek_short(fhandle):
    pos = fhandle.tell()
    res, = struct.unpack('>h', fhandle.read(2))
    fhandle.seek(pos)
    return res


def lookup_char(value):
    if 0 <= value < 400:
        return tileset[value]
    elif value == 20000:
        return '\n'
    elif value == 30000:
        return '<EOM>'
    assert False


def decode_header(header):
    offsets = []
    while True:
        offset = read_word(header)
        if offset == 0:
            break
        offsets.append(offset)
    return offsets


def decode_control_chars(fhandle):
    converted = []
    # FIXME: handle @@ bug better
    while True:
        char = read_short(fhandle)
        if char == 336:
            if peek_short(fhandle) == 336:
                # assume this was a mistake and ignore it
                converted.append('@')
                continue
            # normal flow
            next_char = read_short(fhandle)
            # 'C' or 'c' for Color
            if next_char in (339, 371):
                color = read_short(fhandle)
                if color in (338, 370):    # 'B/b' Blue
                    color_text = '<BLUE>'
                elif color in (339, 371):  # 'C/c' Cyan
                    color_text = '<CYAN>'
                elif color in (343, 375):  # 'G/g' Green
                    color_text = '<GREEN>'
                elif color in (352, 384):  # 'P/p' Purple
                    color_text = '<PURPLE>'
                elif color in (354, 386):  # 'R/r' Red
                    color_text = '<RED>'
                elif color in (359, 391):  # 'W/w' White
                    color_text = '<WHITE>'
                elif color in (360, 370):  # 'X/x' Black
                    color_text = '<BLACK>'
                elif color in (361, 393):  # 'Y/y' Yellow
                    color_text = '<YELLOW>'
                else:
                    # all known colors are mapped
                    assert False

                if next_char == 371:  # lowercase only appears in japanese text
                    color_text = color_text.lower()

                converted.append(color_text)
            # 'N' for New Line
            elif next_char == 350:
                converted.append('<N>')
            # 'G' or 'g' for ... uh sprintf?
            elif next_char in (343, 375):
                mnemonic = '<TIMER>'
                # 'g' only appears in Japanese text
                if next_char == 375:
                    mnemonic = mnemonic.lower()
                converted.append(mnemonic)
            # BUG 1
            elif next_char == 321:
                # should be '<TIMER>15' but control char is missing
                converted.append('@1')
            # BUG 2
            elif next_char == 322:
                # should be '<TIMER>28' but control char is missing
                converted.append('@2')
            else:
                # all scenarios should be covered...
                assert False
        # '#'
        elif char == 307:
            next_char = read_short(fhandle)
            assert next_char in (307, 355)
            if next_char == 307:
                # mission objectives
                converted.append('<MISSION_OBJECTIVE>')
            else:
                # mission brief
                converted.append('<MISSION_BRIEF>')
        else:
            # should not be able to reach here
            assert False

        break
    return ''.join(converted)


def decode_message(fhandle):
    message = []

    # discard message length
    read_short(fhandle)

    while True:
        pos = fhandle.tell()
        char = read_short(fhandle)

        if char == 30000:
            break

        if char in (307, 336):
            # reset position
            fhandle.seek(pos)
            converted = decode_control_chars(fhandle)
        else:
            converted = lookup_char(char)

        message.append(converted)

    return ''.join(message)


def decode_messages(fhandle):
    messages = []
    num_messages = read_short(fhandle)

    for _ in range(num_messages):
        message = decode_message(fhandle)
        messages.append(message)

    return messages


def encode_control_chars(message):
    if message.startswith('<MISSION_BRIEF>'):
        return (struct.pack('>2h', *[307, 355]), 15)
    if message.startswith('<MISSION_OBJECTIVE>'):
        return (struct.pack('>2h', *[307, 307]), 19)
    # newline
    if message.startswith('<N>'):
        return (struct.pack('>2h', *[336, 350]), 3)
    # 'time' related
    if message.startswith('<TIMER>'):
        return (struct.pack('>2h', *[336, 343]), 7)
    if message.startswith('<timer>'):
        return (struct.pack('>2h', *[336, 375]), 7)
    # colors
    if message.startswith('<BLUE>'):
        return (struct.pack('>3h', *[336, 339, 338]), 6)
    if message.startswith('<CYAN>'):
        return (struct.pack('>3h', *[336, 339, 339]), 6)
    if message.startswith('<GREEN>'):
        return (struct.pack('>3h', *[336, 339, 343]), 7)
    if message.startswith('<PURPLE>'):
        return (struct.pack('>3h', *[336, 339, 352]), 8)
    if message.startswith('<RED>'):
        return (struct.pack('>3h', *[336, 339, 354]), 5)
    if message.startswith('<WHITE>'):
        return (struct.pack('>3h', *[336, 339, 359]), 7)
    if message.startswith('<BLACK>'):
        return (struct.pack('>3h', *[336, 339, 360]), 7)
    if message.startswith('<YELLOW>'):
        return (struct.pack('>3h', *[336, 339, 361]), 8)
    if message.startswith('<yellow>'):
        return (struct.pack('>3h', *[336, 371, 393]), 8)
    # should not end up here
    assert False


def encode_message(message):
    res = bytearray()

    cursor = 0
    while cursor < len(message):
        char = message[cursor]
        if char == '<':
            bytes, processed = encode_control_chars(message[cursor:])
        elif char == '\n':
            bytes = struct.pack('>h', 20000)
            processed = 1
        else:
            idx = tileset_dict[char]
            bytes = struct.pack('>h', idx)
            processed = 1
        res += bytes
        cursor += processed
    # append <EOM>
    res += struct.pack('>h', 30000)
    return res


def bin2json(infile, outfile):
    f = open(infile, 'rb')

    result = []
    offsets = decode_header(f)

    # skip over header
    f.seek(48)

    for i, offset in enumerate(offsets):
        segment = {}

        messages = decode_messages(f)
        segment['messages'] = messages

        # junk / padding?
        if i < len(offsets) - 1:
            padding = f.read(offsets[i+1] - f.tell())
        else:
            padding = f.read()

        if len(padding) > 0:
            segment['padding'] = struct.unpack(f'>{len(padding)//2}h', padding)

        result.append(segment)

    with open(outfile, 'w') as o:
        json.dump(result, o, indent=2, ensure_ascii=False)


def json2bin(infile, outfile):
    with open(infile, 'r') as f:
        data = json.load(f)

    result = bytearray()

    # 9 languages, 3 words of padding
    offsets = 12 * [0]

    for i, segment in enumerate(data):
        # append current offset (plus header size)
        offsets[i] = len(result) + 4 * 12

        messages = segment['messages']
        # add num messages
        result += struct.pack('>h', len(messages))
        # add each message
        for message in messages:
            encoded = encode_message(message)
            # add message length
            result += struct.pack('>h', len(encoded))
            # add message
            result += encoded

        # if only this was simply zero padding...
        if 'padding' in segment:
            padding = segment['padding']
            result += struct.pack(f'>{len(padding)}h', *padding)

    header = struct.pack('>12i', *offsets)

    with open(outfile, 'wb') as o:
        o.write(header + result)


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('infile', type=str)
    parser.add_argument('outfile', type=str)
    parser.add_argument('--encode', action='store_true')
    args = parser.parse_args()
    # default to bin->json but support encoding too
    if args.encode:
        json2bin(args.infile, args.outfile)
    else:
        bin2json(args.infile, args.outfile)


if __name__ == '__main__':
    main()
