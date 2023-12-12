/*
 * This file is part of the EMLIB Library.
 *
 * Copyright (c) 2018-Now, Gladtbam, <https://github.com/Gladtbam/EMLIB>
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
 * Function:PkgProtocol API interface function declaration.
 * Created on: 2015-06-17  the first version 
 */
#ifndef __PKGPROTOCOL_H
#define __PKGPROTOCOL_H 	

#ifdef __cplusplus
extern "C" {
#endif

# include "FIFO.H"
# include "Stopwatch.h"

/**PKG Protocol Constitution
 *|----------------------Little Endian----------------------|
 *                       |----CRC8----|
 *|-IdentificationHeader-|-DataLength-|--CRC8--|-DataBuffer-|
 *|--------4 Byte--------|---1 Byte---|-1 Byte-|-1-255 Byte-|
*/


# define PkgMaxSize 255 //Maximum length of data that can be transmitted in a single packet
# define COMRXFIFOBufferSize 522//=(4+1+1+255)*2 //FIFO Minimum buffer length=(Sigle packge maximum length)*2
# define COMTXFIFOBufferSize 522//=(4+1+1+255)*2 //FIFO Minimum buffer length=(Sigle packge maximum length)*2

typedef struct
{
	char* PkgTXHeader;
	char* PkgRXHeader;

	Stopwatch_S COMRXPkgSW;
	Stopwatch_S COMTXPkgSW;
	unsigned int COMRXPkgTimeOutPeriod;
	FIFO_S COMRXFIFO;
	unsigned char COMRXFIFOBuffer[COMRXFIFOBufferSize];
	unsigned char COMRXPkgAnalysisStatus;
	unsigned char COMRXPkgAnalysisLength;
	unsigned char COMRXPkgAnalysisCRC8;
	unsigned char COMRXPkgAnalysisCount;
	unsigned char COMRXPkgAnalysisCRC8Result;
	unsigned char COMRXPkgAnalysisBuffer[PkgMaxSize];
	signed char COMRXPkgAnalysisResult;
	unsigned int COMRXPkgAnalysisFIFOOffset;
	unsigned char NewPkg;

	FIFO_S COMTXFIFO;
	unsigned char COMTXFIFOBuffer[COMTXFIFOBufferSize];
	unsigned int TXWaitTime;
}PkgProtocol_S;

/**
 * Initialize the packet transport protocol stack
 * \param PkgProtocol A pointer to the protocol stack structure
 * \param PkgTXHeader A pointer to the send packet identification header(data length must be 4 bytes)
 * \param PkgRXHeader A pointer to the receive packet identification header(data length must be 4 bytes)
 * \return None
 */
void PkgProtocolInit(PkgProtocol_S* PkgProtocol,const char* PkgTXHeader,const char* PkgRXHeader);

/**
 * Try to get a packet received by the protocol stack(The key content of the packet is captured)
 * \param PkgProtocol A pointer to the protocol stack structure
 * \param Buffer A pointer to the packet data receive buffer(buffer length must be greater than 255 bytes)
 * \param Length A pointer to the packet data receive buffer length
 * \return Whether a packet was received (1-Yes 0-No)
 */
unsigned char PkgProtocolGetRXPkg(PkgProtocol_S* PkgProtocol, unsigned char* Buffer, unsigned char* Length);

/**
 * Send a packet to the protocol stack(The package structure is automatically built by providing the core data within the package)
 * \param PkgProtocol A pointer to the protocol stack structure
 * \param Package A pointer to the packet data send buffer
 * \param PackageLength The data send buffer length
 * \return Whether a send packet was successed to write in the protocol stack (1-Yes 0-No)
 */
unsigned char PkgProtocolSendPkg(PkgProtocol_S* PkgProtocol, unsigned char* Package, unsigned char PackageLength);
/**
 * Write a send packet to the protocol stack FIFO(Send data package  need to be constructed in advance according to the protocol)
 * \param PkgProtocol A pointer to the protocol stack structure
 * \param Data A pointer to the packet data send buffer
 * \param Length The packet data send buffer length
 * \return Whether a send packet was successed to write in the protocol stack FIFO (1-Yes 0-No)
 */
unsigned int PkgProtocolWriteTXFIFO(PkgProtocol_S* PkgProtocol, unsigned char* Data, unsigned int Length);
/**
 * Write a send packet to the custom FIFO(No protocol stack dependencies)(Send data package  need to be constructed in advance according to the protocol)
 * \param FIFO A pointer to the FIFO structure
 * \param Package A pointer to the packet data send buffer
 * \param PackageLength The packet data send buffer length
 * \param PkgTXHeader A pointer to the send packet custom identification header(data length must be 4 bytes)
 * \return Whether a send packet was successed to write in the FIFO (1-Yes 0-No)
 */
unsigned char PkgProtocolSendPkgFIFO(FIFO_S* FIFO, unsigned char* Package, unsigned char PackageLength, const char* PkgTXHeader);

/**
 * The protocol stack packet receives processing tasks
 * \param PkgProtocol A pointer to the protocol stack structure
 * \return None
 */
void PkgProtocolRXPkgAnalysisTask(PkgProtocol_S* PkgProtocol);

/**
 * The received data buffer is written to the protocol stack to receive the FIFO(hardware layer)
 * \param PkgProtocol A pointer to the protocol stack structure
 * \param Data A pointer that stores the received data to be written
 * \param Length The length of the received data to be written
 * \return Whether the data is written successfully (1-Yes 0-No)
 */ 
unsigned char PkgProtocolWriteRXFIFO(PkgProtocol_S* PkgProtocol, unsigned char* Data, unsigned int Length);

/**
 * The send data is read from the protocol stack send FIFO data to the buffer   
 * \param PkgProtocol A pointer to the protocol stack structure
 * \param Data A pointer to read the FIFO data to be sent in the protocol stack
 * \param Length Read the length of the FIFO data to be sent in the protocol stack
 * \return Whether the data is read successfully (1-Yes 0-No)
 */
unsigned int PkgProtocolReadTXFIFO(PkgProtocol_S* PkgProtocol, unsigned char* Data, unsigned int Length);

/**
 * Protocol stack data sending task at the hardware layer 
 * \param PkgProtocol A pointer to the protocol stack structure
 * \param COMByteSize Maximum data size that a hardware port can send at once time
 * \param MaxWaitTime Maximum wait period times when the number of data to be sent is less than the maximum number of data that can be sent on a port at a time(0-Not wait)
 * \param Reserve     Reserve parameter
 * \param COMSend     Send interface at the hardware layer(If the return value is 1, the transmission is successful.The send failure buffer retains the sent content and resends it until it succeeds.)
 * \return The number of data attempts to send
 */
unsigned char PkgProtocolCOMTXTask(PkgProtocol_S* PkgProtocol, unsigned char COMByteSize,unsigned char MaxWaitTime, unsigned int Reserve, signed char(*COMSend)(unsigned char* Buffer, unsigned char Length, unsigned int Reserve));

/**
 * Custom FIFO data sending task at the hardware layer 
 * \param FIFO A pointer to the custom FIFO
 * \param COMByteSize Maximum data size that a hardware port can send at once time
 * \param MaxWaitTime Maximum wait period times when the number of data to be sent is less than the maximum number of data that can be sent on a port at a time(0-Not wait)
 * \param Reserve     Reserve parameter
 * \param COMSend     Send interface at the hardware layer(If the return value is 1, the transmission is successful.The send failure buffer retains the sent content and resends it until it succeeds.)
 * \return The number of data attempts to send
 */
unsigned char PkgProtocolCOMTXFIFOTask(FIFO_S* FIFO, unsigned char COMByteSize, unsigned int* DataWaitTime, unsigned int AddTimeSpan, unsigned int MaxWaitTime, unsigned int Reserve, signed char(*COMSend)(unsigned char* Buffer, unsigned char Length, unsigned int Reserve));

/**
 * Clear the protocol stack send buffer
 * \param PkgProtocol A pointer to the protocol stack structure
 * \return None
 */
void PkgProtocolFlushTXFIFO(PkgProtocol_S* PkgProtocol);
/**
 * Clear the protocol stack receive buffer
 * \param PkgProtocol A pointer to the protocol stack structure
 * \return None
 */
void PkgProtocolFlushRXFIFO(PkgProtocol_S* PkgProtocol);

/**
 * Gets the protocol readable length of the receive buffer
 * \param PkgProtocol A pointer to the protocol stack structure
 * \return Number of bytes
 */
unsigned int PkgProtocolGetRXFIFOReadSize(PkgProtocol_S* PkgProtocol);
/**
 * Gets the protocol writable length of the receive buffer
 * \param PkgProtocol A pointer to the protocol stack structure
 * \return Number of bytes
 */
unsigned int PkgProtocolGetRXFIFOWriteSize(PkgProtocol_S* PkgProtocol);
/**
 * Gets the protocol readable length of the send buffer
 * \param PkgProtocol A pointer to the protocol stack structure
 * \return Number of bytes
 */
unsigned int PkgProtocolGetTXFIFOReadSize(PkgProtocol_S* PkgProtocol);
/**
 * Gets the protocol writable length of the send buffer
 * \param PkgProtocol A pointer to the protocol stack structure
 * \return Number of bytes
 */
unsigned int PkgProtocolGetTXFIFOWriteSize(PkgProtocol_S* PkgProtocol);


#ifdef __cplusplus
}
#endif


#endif
