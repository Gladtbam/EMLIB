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
 * Function:FIFO API interface function declaration.
 * Created on: 2015-05-20  the first version 
 */
#ifndef __FIFO_H
#define __FIFO_H 	

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
	void* Pointer;
	unsigned int TypeSize;
	unsigned int Capacity;
	volatile unsigned int PWrite;
	volatile unsigned int PRead;
}
FIFO_S;

/**
 * Initialize the FIFO structure
 * \param FIFO A pointer to the FIFO structure
 * \param Addr A pointer to the FIFO buffer
 * \param Capacity Size of the FIFO buffer
 * \param TypeSize The data size of a single data in FIFO
 * \return Whether the FIFO was successfully initialized
 */
unsigned char FIFOInit(FIFO_S* FIFO, void* Addr, unsigned int Capacity, unsigned short TypeSize);

/**
 * Flush the FIFO readable cache
 * \param FIFO A pointer to the FIFO structure
 * \return None
 */
void FIFOFlush(FIFO_S* FIFO);

/**
 * Reset the FIFO
 * \param FIFO A pointer to the FIFO structure
 * \return None
 */
void FIFOReset(FIFO_S* FIFO);

/**
 * Gets the size of FIFO readable bytes
 * \param FIFO A pointer to the FIFO structure
 * \return Readable bytes size
 */
unsigned int FIFOGetReadByteSize(FIFO_S* FIFO);

/**
 * Gets the size of FIFO writable bytes
 * \param FIFO A pointer to the FIFO structure
 * \return Writable bytes size
 */
unsigned int FIFOGetWriteByteSize(FIFO_S* FIFO);

/**
 * Attempts to read a specified amount of data from the FIFO(The read pointer in the FIFO will be moved after a successful read)
 * \param FIFO A pointer to the FIFO structure
 * \param DataBuffer A buffer pointer to receiving read data
 * \param DataLength The amount of data to attempt to read
 * \return Number of data read
 */
unsigned int FIFORead(FIFO_S* FIFO, void* DataBuffer, unsigned int DataLength);

/**
 * Attempts to read a specified amount of data from the FIFO(The read pointer in the FIFO will not be moved after a successful read)
 * \param FIFO A pointer to the FIFO structure
 * \param DataBuffer A buffer pointer to receiving read data
 * \param DataLength The amount of data to attempt to read
 * \param DataOffset Offset address of the read pointer
 * \return Number of data read
 */
unsigned int FIFOVirtualRead(FIFO_S* FIFO, void* DataBuffer, unsigned int DataLength, unsigned int DataOffset);

/**
 * Attempts to write a specified amount of data from the FIFO(The write pointer in the FIFO will be moved after a successful write)
 * \param FIFO A pointer to the FIFO structure
 * \param DataBuffer A buffer pointer to writed data
 * \param DataLength The amount of data to attempt to read
 * \return Number of data write
 */
unsigned char FIFOWrite(FIFO_S* FIFO, const void* DataBuffer, unsigned int DataLength);

/**
 * Attempts to read one byte from the FIFO(The read pointer in the FIFO will be moved after a successful read)
 * \param FIFO A pointer to the FIFO structure
 * \param Byte A byte pointer to receiving read data
 * \return Number of byte read
 */
unsigned char FIFOReadByte(FIFO_S* FIFO, void* Byte);

/**
 * Attempts to read one byte from the FIFO(The read pointer in the FIFO will not be moved after a successful read)
 * \param FIFO A pointer to the FIFO structure
 * \param DataBuffer A byte pointer to receiving read data
 * \param DataOffset Offset address of the read pointer
 * \return Number of data read
 */
unsigned char FIFOVirtualReadByte(FIFO_S* FIFO, void* Byte, unsigned int ByteOffset);

/**
 * The read pointer of the FIFO is moved in bytes step
 * \param FIFO A pointer to the FIFO structure
 * \param ByteLength The length of bytes to be moved
 * \return Number of data read
 */
unsigned char FIFOMoveReadPoint(FIFO_S* FIFO, unsigned int ByteLength);

/**
 * Attempts to write one byte from the FIFO(The write pointer in the FIFO will be moved after a successful write)
 * \param FIFO A pointer to the FIFO structure
 * \param Byte A byte pointer to writed byte
 * \return Number of data write
 */
unsigned char FIFOWriteByte(FIFO_S* FIFO, void* Byte);

/**
 * Copy between arrays
 * \param Dest        Pointer to the array to copy to
 * \param Source      Pointer to the array to copy from
 * \param Length      Length to copy
 * \return Pointer to the destination array
 */
void* FIFOArrayCopy(void* Dest, const void* Source, unsigned int Length);

#ifdef __cplusplus
}
#endif

#endif
