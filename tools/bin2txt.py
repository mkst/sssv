import struct
import sys

# huge thanks to Wedarobi + PeterFoxSNS + blu for identifying the majority of Japanese characters!

# 336 (@) control character
# 307 (#) control character, not used in any dialog

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
    '攻', '撃', '爆', '破', '救', '出', '乗', '運', '行', '島', '建', '物', '博', '士', '戦', '車',
    '飛', '機', '発', '見', '南', '極', '魔', '王', '日', '本', '壊', '水', '前', '後', '病', '院',
    '死', '全', '自', '動', '遂', '工', '場', '沈', '船', '客', '火', '山', '案', '内', '燃', '料',
    '逃', '亡', '所', '守', '輸', '送', '武', '器', '庫', '安', '現', '銃', '弾', '時', '間', '…',
    '歩', '兵', '正', '村', '防', '使', '敵', '変', '異', '学', '校', '教', '団', '子', '供', '調',
    'À', 'Â', 'Ç', 'É', 'È', 'Ê', 'Ï', 'Î', 'Ô', 'Û', 'Ü', 'Ú', 'Æ', 'Ä', 'Ö', '^', # another ù?
    'à', 'â', 'ç', 'é', 'è', 'ê', 'ï', 'î', 'ô', 'û', 'ü', 'ú', 'œ', 'ä', 'ö', 'ß',
    '¡', '¿', 'Ó', 'á', 'ñ', 'Ñ', 'ã', 'Ã', 'õ', 'Õ', 'í', 'ó', 'ù', 'À', 'ì', '¬',
    ' ', '!', '"', '#', '犬', '岩', 'ò', "'", '生', '砂', '—', '巨', ',', '-', '.', '大',
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ';', '滅', '‒', '絶', '|', '?',
    '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O',
    'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '♫', '🔊', '☑️', '☐', 'Í',
    '物', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o',
    'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'ヴ', 'ひ', '口', 'な', '笑',

    # in final row, ひ and な are duplicates that DO occur, so need an alternative for them.
]

languages = [
    'AMERICAN',
    'DUTCH',
    'ENGLISH',
    'FRENCH',
    'GERMAN',
    'ITALIAN',
    'JAPANESE',
    'PORTUGESE',
    'SPANISH',
]

def read_short(data, is_be=True):
    endian = '>' if is_be else '<'
    res, = struct.unpack(endian + 'h', data)
    return res

def read_word(data, is_be=True):
    endian = '>' if is_be else '<'
    res, = struct.unpack(endian + 'i', data)
    return res

def lookup_char(value):
    # sanity
    assert 0 <= value < 400

    return tileset[value]

def parse_header(header, is_be=True):
    # sanity
    assert len(header) > 4

    cursor = 0
    offsets = []
    while True:
        offset = read_word(header[cursor:cursor+4], is_be)
        cursor += 4
        if offset == 0:
            break
        offsets.append(offset)
    return offsets

def parse_control_chars(data, is_be=True):
    cursor = 0
    converted = []

    while True:
        char = read_short(data[cursor:cursor+2], is_be)
        cursor += 2
        # need to identify all control chars
        if char == 336:
            next_char = read_short(data[cursor:cursor+2], is_be)
            cursor += 2
            # 'C' (color selection)
            if next_char == 339:
                color = read_short(data[cursor:cursor+2], is_be)
                cursor += 2
                if color == 338:            # 'B' Blue
                    color_text = '<BLUE>'
                elif color == 339:          # 'C' Cyan, unused
                    color_text = '<CYAN>'
                elif color == 343:          # 'G' Green
                    color_text = '<GREEN>'
                elif color == 352:          # 'P' Purple
                    color_text = '<PURPLE>'
                elif color == 354:          # 'R' Red
                    color_text = '<RED>'
                elif color == 359:          # 'W' White
                    color_text = '<WHITE>'
                elif color == 361:          # 'Y' Yellow
                    color_text = '<YELLOW>'
                elif color == 360:          # 'X' Black, unused
                    color_text = '<BLACK>'
                else:
                    sys.stderr.write("Unknown color %i\n" % color)
                    color_text = '<UNKNOWN>'
                converted.append(color_text)
            #
            elif next_char == 350:          # 'N'
                converted.append('\n')
            elif next_char == 336:          #
                next_char = read_short(data[cursor+2:cursor+4], is_be)
                sys.stderr.write("two control characters in a row, next one is %i\n" % next_char)
                converted.append('_4_')
            elif next_char == 343:          # 'G'
                converted.append('_5_') # timer e.g. _5_25;_5_28 -< %m:%s ?
            else:
                sys.stderr.write('unexpected control char %i\n' % next_char)
                converted.append('_6_')
            # 321
            # 322
            # 371
            # 375
        elif char == 307:
            converted.append('<MISSION_CHARACTER>')
            next_char = read_short(data[cursor:cursor+2], is_be)
            cursor += 2
            if next_char == 355:        #   'S'
                converted.append('<c>')
            elif next_char == 307:      #   '#'
                converted.append('<3>')
            else:
                sys.stderr.write('unexpected MISSION_CHARACTER %i\n' % next_char)
                converted.append('<!>')
        else:
            converted.append('?')
        break
    return (''.join(converted), cursor)

def decode_message(data, is_be=True):
    # sanity (smallest message is just <EOM>)
    assert len(data) >= 2

    ret = []
    cursor = 0
    while cursor < len(data):
        char = read_short(data[cursor:cursor+2], is_be)

        # in order to handle multi-character control commands
        processed = 0

        if char == 30000: # end
            converted = '<EOM>'
            processed = 2
        elif char == 20000: # newline
            converted = '\r\n'
            processed = 2
        elif char in [307, 336]:
            # vals = [int(x) for x in struct.unpack(">hhhh", data[cursor:cursor+8])]
            # print("cursor:", cursor, vals, [tileset[x] for x in vals])
            converted, processed = parse_control_chars(data[cursor:], is_be)
        else:
            converted = lookup_char(char)
            processed = 2

        ret.append(converted)
        cursor += processed

    # append newline to each message
    ret.append('\r\n')
    joined = ''.join(ret)
    return joined

def decode_section(data, is_be=True):
    ret = []
    cursor = 0
    num_messages = read_short(data[cursor:cursor+2], is_be)
    ret.append('<NumberMessages> %i' % num_messages)
    cursor += 2
    i = 0
    while i < num_messages and cursor < len(data):
        # read message length
        length = read_short(data[cursor:cursor+2], is_be)
        cursor += 2

        if length == 0:
            # probably padding?
            continue

        ret.append('<MessageSize> %i' % length)

        # else parse message
        msg = decode_message(data[cursor:cursor+length], is_be)

        cursor += length
        ret.append(msg)
        i += 1
    return ret

def main():
    # is big endian? N64 True, PS1 False (different tileset)
    is_be = True

    with open(sys.argv[1], 'rb') as infile:
        data = infile.read()

    result = []
    offsets = parse_header(data, is_be)

    for i, offset in enumerate(offsets):
        language = '<Language>\t%s' % languages[i]
        decoded = '\r\n'.join(decode_section(data[offsets[i]:], is_be))
        result.append('\r\n'.join([language, decoded]))

    # each language is separated by 3 newlines
    print('\r\n\r\n\r\n'.join(result))

if __name__ == '__main__':
    main()
