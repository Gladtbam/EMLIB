/*
 * This file is part of the EMLIB Library.
 *
 * Copyright (c) 2015-Now, Gladtbam, <https://github.com/Gladtbam/EMLIB>
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * 'Software'), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED 'AS IS', WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * Function:Hash API interface function declaration.
 * Created on: 2015-02-11  the first version 
 */
#ifndef __HASH_H
#define __HASH_H 	

#ifdef __cplusplus
extern "C" {
#endif


void* HashArrayCopy(void* Dest, const void* Source, unsigned int Length);

/*
* Name:        CRC-8_SMBUS
* Width:       8
* Poly:        0x07(x8+x2+x+1)   
* InitialValue:0x00(Function Is 0x00)
* DataRef:     False
* XOROut:      0x00
* Funcion InitialValue:0x00
*/
unsigned char HashCRC8(const void* Buffer, unsigned int Length, unsigned char InitialValue);
/*
* Name:        CRC-32_ISO-HDLC
* Width:       32
* Poly:        0x04C11DB7(x32+x26+x23+x22+x16+x12+x11+x10+x8+x7+x5+x4+x2+x+1)
* InitialValue:0xFFFFFFFF
* DataRef:     True
* XOROut:      0xFFFFFFFF
* Funcion InitialValue:0x00000000
*/
unsigned int HashCRC32(const void* Buffer, unsigned int Length, unsigned int InitialValue);
/*
* Name:        CRC-32_MPEG-2
* Width:       32
* Poly:        0x04C11DB7(x32+x26+x23+x22+x16+x12+x11+x10+x8+x7+x5+x4+x2+x+1)
* InitialValue:0xFFFFFFFF
* DataRef:     False
* XOROut:      0x00000000
* Funcion InitialValue:0xFFFFFFFF
*/
unsigned int HashCRC32_MPEG2(const void* Buffer, unsigned int Length, unsigned int InitialValue);
/*
* Name:        CRC-64_XZ
* Width:       64
* Poly:        0x42F0E1EBA9EA3693(x64+x62+x57+x55+x54+x53+x52+x47+x46+x45+x40+x39+x38+x37+x35+x33+x32+x31+x29+x27+x24+x23+x22+x21+x19+x17+x13+x12+x10+x9+x7+x4+x+1)
* InitialValue:0xFFFFFFFFFFFFFFFF
* DataRef:     True
* XOROut:      0xFFFFFFFFFFFFFFFF
* Funcion InitialValue:0x0000000000000000
*/
unsigned long long HashCRC64(const void* Buffer, unsigned int Length, unsigned long long InitialValue);
/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
* MD5 Utils
*////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct
{
	unsigned int Count[2];
	unsigned int State[4];
	unsigned char Block[64];
}HashMD5_S;
void HashMD5Init(HashMD5_S* HashMD5);
void HashMD5Calculate(HashMD5_S* HashMD5, unsigned char* Buffer, unsigned int Length);
void HashMD5Result(HashMD5_S* HashMD5, unsigned char MD5Result[16]);

#ifdef __cplusplus
}
#endif

#endif
