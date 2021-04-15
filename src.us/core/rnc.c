/*----------------------------------------------------------------------------
 * PROPACK Unpacker 'C' Source Code
 *
 * Copyright (c) 1995 Rob Northen Computing, UK. All Rights Reserved.
 *
 * File: UNPACK.C
 *
 * Date: 18.03.95
 *----------------------------------------------------------------------------*/

#if 0
#include <malloc.h>
#include <mem.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#endif

#include "pp.h"

#if 0
BYTE BitBuffM2,
     *OutputEnd;

ULONG BitBuffM1;
#else
extern BYTE BitBuffM2,
     *OutputEnd;

extern ULONG BitBuffM1;
#endif

WORD UnpackRNC(RNC_fileptr, BYTE *OutputBuffer);
WORD UnpackMethod1(RNC_fileptr FilePtr, BYTE *OutputBuffer);
WORD UnpackMethod2(RNC_fileptr FilePtr, BYTE *OutputBuffer);
void InitUnpack(RNC_fileptr FilePtr, BYTE *OutputBuffer);
WORD InputBitsM1(BYTE n);
WORD InputBitsM2(BYTE n);
void InputHuffmanTable(HUFFMAN_tableptr Table, BYTE TableSize);
WORD InputValue(HUFFMAN_tableptr Table);
WORD InputLenM2(void);
WORD InputPosM2(void);

ULONG ReverseLong(BYTE *b);
WORD  ReverseWord(BYTE *b);

#if 0
int main(int argc, char *argv[])
{
    BYTE *InputBuffer,
         *OutputBuffer;

    int handle;

    ULONG FileSize,
         UncompressedSize;

    if (argc < 2) {
        printf("filename required.\n");
        exit(EXIT_FAILURE);
    }

    if ((handle = open(argv[1], O_RDONLY | O_BINARY)) == -1) {
        printf("failed to open: %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    FileSize = filelength(handle);

    if ((InputBuffer = (BYTE *)malloc(FileSize)) == NULL) {
        printf("failed to allocate input buffer\n");
        exit(EXIT_FAILURE);
    }

    if (read(handle, InputBuffer, FileSize) != FileSize) {
        close(handle);
        printf("failed to read file\n");
        exit(EXIT_FAILURE);
    }

    close(handle);

    UncompressedSize = BIGENDIANL(((RNC_fileptr)InputBuffer)->UncompressedSize);

    if ((OutputBuffer = (BYTE *)malloc(UncompressedSize)) == NULL) {
        free((void *)InputBuffer);
        printf("failed to allocate output buffer\n");
        exit(EXIT_FAILURE);
    }

    if (UnpackRNC((RNC_fileptr)InputBuffer, OutputBuffer) != 0) {
        printf("failed to unpack RNC file\n");
        free((void *)InputBuffer);
        free((void *)OutputBuffer);
        exit(EXIT_FAILURE);
    }

    free((void *)InputBuffer);
    free((void *)OutputBuffer);
    return(EXIT_SUCCESS);
}
#endif

WORD UnpackRNC(RNC_fileptr FilePtr, BYTE *OutputBuffer)
{
    WORD    result;
    BYTE    *string;

    string = (BYTE *)&FilePtr->Id[0];

    if ((string[0] != 'R') || (string[1] != 'N') || (string[2] != 'C'))
        return RNCERROR_BADFILEID;


    switch (FilePtr->Method) {
        case 0:
#if 1
            // do nothing
#else
            memcpy(OutputBuffer, &FilePtr->Data, BIGENDIANL(FilePtr->UncompressedSize));
#endif
            result = RNCERROR_OK;
            break;

        case 1:
            result = UnpackMethod1(FilePtr, OutputBuffer);
            break;

        case 2:
            result = UnpackMethod2(FilePtr, OutputBuffer);
            break;

        default:
            result = RNCERROR_UNKNOWNMETHOD;
    }

    return result;
}

WORD UnpackMethod1(RNC_fileptr FilePtr, BYTE *OutputBuffer)
{
#if 1
    WORD rs;
    ULONG rw;
#endif
    BYTE *Ptr;

    WORD LoopCount,
         Len;

    InitUnpack(FilePtr, OutputBuffer);

    InputBitsM1(2); // lock and key bits

    while (OutputPtr < OutputEnd) {
        InputHuffmanTable(&RawHuffmanTable[0], 16);
        InputHuffmanTable(&PosHuffmanTable[0], 16);
        InputHuffmanTable(&LenHuffmanTable[0], 16);
        LoopCount = InputBitsM1(16);
        goto Start;

        Again:
            Ptr = OutputPtr - (InputValue(PosHuffmanTable) + 1);
            Len = InputValue(LenHuffmanTable) + 2;
            while (Len--)
                *OutputPtr++ = *Ptr++;
        Start:
            Len = InputValue(RawHuffmanTable);
            while (Len--)
                *OutputPtr++ = *InputPtr++;
#if 1
            rs = ReverseWord(InputPtr + 1);
            rw = ReverseLong(InputPtr + 2) << 16;
            BitBuffM1 = (((*InputPtr + rw + (rs << 8)) << BitBuffBits) +
                          (BitBuffM1 & ((1 << BitBuffBits) - 1)));
#else
            BitBuffM1 = ((((ULONG)*(InputPtr+2) << 16) + ((WORD)*(InputPtr+1) << 8) + *InputPtr) << BitBuffBits)
                         + (BitBuffM1 & (1 << BitBuffBits) - 1);
#endif

            if (--LoopCount) goto Again;
    }

    return RNCERROR_OK;
}

WORD UnpackMethod2(RNC_fileptr FilePtr, BYTE *OutputBuffer)
{
    BYTE *Ptr;

    WORD Pos,
         Len;

    InitUnpack(FilePtr, OutputBuffer);

    InputBitsM2(2); // lock and key bits

    while (OutputPtr < OutputEnd) {
        for (;;) {
            while (InputBitsM2(1) == 0)
                *OutputPtr++ = *InputPtr++;
            if (InputBitsM2(1)) {
                if (InputBitsM2(1) == 0) {
                    Len = 2;
                    Pos = *InputPtr++ + 1;
                } else {
                    if (InputBitsM2(1) == 0)
                        Len = 3;
                    else {
                        if ((Len = *InputPtr++ + 8) == 8)
                            break;
                    }
                    Pos = InputPosM2();
                }
                Ptr = OutputPtr - Pos;
                while (Len--)
                    *OutputPtr++ = *Ptr++;
            }
            else {
                if ((Len = InputLenM2()) == 9) {
                    Len = (InputBitsM2(4) << 2) + 12;
                    while (Len--)
                        *OutputPtr++ = *InputPtr++;
                } else {
                    Ptr = OutputPtr - InputPosM2();
                    while (Len--)
                        *OutputPtr++ = *Ptr++;
                }
            }
        }
        InputBitsM2(1);
    }

    return RNCERROR_OK;
}

void InitUnpack(RNC_fileptr FilePtr, BYTE *OutputBuffer)
{
#if 1
    ULONG sp2C;
    ULONG sp28;
    ULONG sp24;
    ULONG sp20;
#endif
    InputPtr = (BYTE *)&FilePtr->Data; // skip over header
    OutputPtr = OutputBuffer;
#if 1
    sp24 = ReverseLong((BYTE *)&FilePtr->UncompressedSize);
    sp28 = ReverseLong((BYTE *)&FilePtr->UncompressedSize);
    sp2C = ReverseLong((BYTE *)&FilePtr->UncompressedSize);
    sp20 = ReverseLong((BYTE *)&FilePtr->UncompressedSize);

    OutputEnd = OutputBuffer + ((((sp20 >> 16) & 0xFF00) >> 8) + (((sp2C >> 16) & 0x00FF) << 8) +
                               ((((sp28 & 0xFFFF) << 8) + ((sp24 & 0xFF00) >> 8)) << 16));
#else
    OutputEnd = OutputBuffer + BIGENDIANL(FilePtr->UncompressedSize);
#endif
    BitBuffBits = 0;
}

WORD InputBitsM1(BYTE n)
{
    WORD Bits = 0,
         BitMask = 1;

    while (n--) {
        if (BitBuffBits == 0) {
#if 1
            BitBuffM1 = ReverseLong(InputPtr);
#else
            BitBuffM1 = *((ULONG *)InputPtr);
#endif
            InputPtr += 2;
            BitBuffBits = 16;
        }
        if (BitBuffM1 & 1)
            Bits |= BitMask;
        BitMask <<= 1;
        BitBuffM1 >>= 1;
        BitBuffBits--;
    }

    return Bits;
}

WORD InputBitsM2(BYTE n)
{
    WORD Bits = 0;

    while (n--) {
        if (BitBuffBits == 0) {
            BitBuffM2 = *InputPtr++;
            BitBuffBits = 8;
        }
        Bits <<= 1;
        if (BitBuffM2 & 0x80)
            Bits++;
        BitBuffM2 <<= 1;
        BitBuffBits--;
    }

    return Bits;
}

void InputHuffmanTable(HUFFMAN_tableptr Table, BYTE TableSize)
{
    BYTE n,
         i;

    HUFFMAN_tableptr tableptr;

    InitHuffmanTable(Table, TableSize);

    if ((n = (BYTE)InputBitsM1(5)) != 0) {
        if (n > 16)
            n = 16;
        tableptr = Table;
        for (i = 0; i < n; i++) {
            tableptr->CodeLen = InputBitsM1(4);
            tableptr++;
        }
        MakeHuffmanCodes(Table, n);
    }
}

WORD InputValue(HUFFMAN_tableptr Table)
{
    BYTE Bits = 0;

    HUFFMAN_tableptr tableptr;

    tableptr = Table;

    while ( (tableptr->CodeLen == 0) || ((BitBuffM1 & (1 << tableptr->CodeLen) - 1) != tableptr->Code)) {
        tableptr++;
        Bits++;
    }

    InputBitsM1(tableptr->CodeLen);

    if (Bits < 2)
        return Bits;

    return InputBitsM1(Bits - 1) | (1 << (Bits - 1));
}

WORD InputLenM2(void)
{
    WORD Len = InputBitsM2(1) + 4;

    if (InputBitsM2(1) == 0)
        return Len;

    return ((Len - 1) << 1) + InputBitsM2(1);
}

WORD InputPosM2(void)
{
    WORD Pos = 0;

    if (InputBitsM2(1)) {
        Pos = InputBitsM2(1);
        if (InputBitsM2(1)) {
            Pos = ((Pos << 1) + InputBitsM2(1)) | 4;
            if (InputBitsM2(1) == 0)
                Pos = (Pos << 1) + InputBitsM2(1);
        } else
            if (Pos == 0)
                Pos = InputBitsM2(1) + 2;
    }

    return (Pos << 8) + *InputPtr++ + 1;
}

#if 1
// turns "abcd" => "dcba"
ULONG ReverseLong(BYTE *b) {
    return b[0] | (b[1] << 8) | (b[2] << 16) | (b[3] << 24);
}

// turns "ab" => "ba"
WORD ReverseWord(BYTE *b) {
    return b[0] | (b[1] << 8);
}
#endif

/*----------------------------------------------------------------------------
 * PROPACK Unpacker 'C' Source Code
 *
 * Copyright (c) 1995 Rob Northen Computing, UK. All Rights Reserved.
 *
 * File: HUFFMAN.C
 *
 * Date: 07-APR-95
 *----------------------------------------------------------------------------*/

#if 0
BYTE BitBuffBits,
     *InputPtr,
     *OutputPtr;

WORD FirstEntry,
     SecondEntry;

huffman RawHuffmanTable[16],
        PosHuffmanTable[16],
        LenHuffmanTable[16];
#else
extern WORD FirstEntry,
            SecondEntry;
#endif

void InitHuffmanTable(HUFFMAN_tableptr Table, BYTE TableSize);
void MakeHuffmanCodes(HUFFMAN_tableptr Table, BYTE n);
void MakeHuffmanTable(HUFFMAN_tableptr Table, BYTE n);
WORD FindLowest(HUFFMAN_tableptr Table, BYTE n);
ULONG SwapBits(ULONG InBits, BYTE n);

void InitHuffmanTable(HUFFMAN_tableptr Table, BYTE TableSize)
{
    while (TableSize--) {
        Table->Frequency = 0;
        Table->EntryPtr = USHRT_MAX;
        Table->Code = 0;
        Table->CodeLen = 0;
        Table++;
    }
}

void MakeHuffmanCodes(HUFFMAN_tableptr Table, BYTE n)
{
    WORD huff_bits = 1,
         i;

    ULONG huff_code = 0,
         huff_base = 0x80000000;

    HUFFMAN_tableptr tableptr;

    while (huff_bits <= 16) {
        tableptr = Table;
        for (i = 0; i < n; i++) {
            if (tableptr->CodeLen == huff_bits) {
                tableptr->Code = SwapBits(huff_code / huff_base, huff_bits);
                huff_code += huff_base;
            }
            tableptr++;
        }
        huff_bits++;
        huff_base >>= 1;
    }
}

void MakeHuffmanTable(HUFFMAN_tableptr Table, BYTE n)
{
    WORD i,
         j,
         k;

    ULONG temp[16];

    for (i = 0; i < 16; i++)
        temp[i] = Table[i].Frequency;

    for (i = j = 0; i < n; i++)
        if (Table[i].Frequency) {
            j++;
            k = i;
        }

    if (j == 0)
        return;

    if (j == 1) {
        Table[k].CodeLen++;
        return;
    }

    while (FindLowest(Table, n)) {
        Table[FirstEntry].Frequency += Table[SecondEntry].Frequency;
        Table[SecondEntry].Frequency = 0;
        Table[FirstEntry].CodeLen++;

        while (Table[FirstEntry].EntryPtr !=  USHRT_MAX) {
            FirstEntry = Table[FirstEntry].EntryPtr;
            Table[FirstEntry].CodeLen++;
        }

        Table[FirstEntry].EntryPtr = SecondEntry;
        Table[SecondEntry].CodeLen++;

        while (Table[SecondEntry].EntryPtr != USHRT_MAX) {
            SecondEntry = Table[SecondEntry].EntryPtr;
            Table[SecondEntry].CodeLen++;
        }
    }

    for (i = 0; i < 16; i++)
        Table[i].Frequency = temp[i];

    MakeHuffmanCodes(Table, n);
}

WORD FindLowest(HUFFMAN_tableptr Table, BYTE n)
{
    BYTE Entry;

    ULONG Freq,
         FirstFreq  = ULONG_MAX,
         SecondFreq = ULONG_MAX;

    for (Entry = 0; Entry < n; Entry++)
        if ((Freq = Table[Entry].Frequency) != 0)
            if (Freq < FirstFreq) {
                SecondFreq  = FirstFreq;
                SecondEntry = FirstEntry;
                FirstFreq   = Freq;
                FirstEntry  = Entry;
            } else
                if (Freq < SecondFreq) {
                    SecondFreq  = Freq;
                    SecondEntry = Entry;
                }
    if ((FirstFreq == ULONG_MAX) || (SecondFreq == ULONG_MAX))
        return 0;
    return 1;
}

ULONG SwapBits(ULONG InBits, BYTE n)
{
    ULONG OutBits = 0;

    while (n--) {
        OutBits <<= 1;
        if (InBits & 1)
            OutBits |= 1;
        InBits >>= 1;
    }

    return OutBits;
}
