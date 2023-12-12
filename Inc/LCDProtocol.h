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
 * Function:TJC LCDProtocol ReceivceProcess API interface function declaration.
 * Created on: 2018-02-11  the first version 
 */
#ifndef __LCDPROTOCOL_H
#define __LCDPROTOCOL_H 	

#ifdef __cplusplus
extern "C" {
#endif

# include "FIFO.H"
# include "Stopwatch.h"

/**TJC LCD Protocol Constitution
 *|-----------------------------------------------LittleEndian-----------------------------------------------|
 *                       |--------------------TJC ModBus CRC16 Caculate-------------------|
 *|-IdentificationHeader-|-Page Index-|--VarIndex--|--Var Type--|-Var Legnth-|--Var Data--|-TJC ModBus CRC16-|
 *|--------4 Byte--------|---1 Byte---|---1 Byte---|---1 Byte---|---1 Byte---|-1-255 Byte-|------2 Byte------|
*/

/**TCJ LCD Code Example - Send a Int32 Value (4 bytes)
 * crcrest 1,0xFFFF
 * crcputs PAGE.val,1
 * crcputh 01 00
 * crcputh 04
 * crcputs 1,4
 * printh AA BB CC DD
 * prints PAGE.val,1
 * printh 01 00
 * printh 04
 * prints 1,4
 * prints crcval,2
*/

/**TCJ LCD Code Example - Send a String (unknow bytes)
 * crcrest 1,0xFFFF
 * crcputs PAGE.val,1
 * crcputh 00 00
 * btlen b1.txt,LENGTH.val
 * LENGTH.val=LENGTH.val+1
 * crcputs LENGTH.val,1
 * crcputs b1.txt,0
 * crcputh 00
 * printh AA BB CC DD
 * prints PAGE.val,1
 * printh 00 00
 * prints LENGTH.val,1
 * prints b1.txt,0
 * printh 00
 * prints crcval,2
*/
# define LCDPkgHeader "\xAA\xBB\xCC\xDD"//Identification Header (cannot be changed)
# define LCDRXFIFOBufferSize 2048//Large array stabilization

typedef struct
{
	unsigned char Page;//Page Index
	unsigned char Index;//Var Index
	unsigned char Type;//Var Type
	unsigned char Length;//Var Legnth
	unsigned char Data[255];//Var Data
}LCDPkg_S;//LCD Information Package

typedef struct
{
	char* PkgRXHeader;

	Stopwatch_S COMRXPkgSW;
	unsigned int COMRXPkgTimeOutPeriod;
	FIFO_S COMRXFIFO;
	unsigned char COMRXFIFOBuffer[LCDRXFIFOBufferSize];
	unsigned char COMRXPkgAnalysisStatus;
	unsigned char COMRXPkgAnalysisLength;
	unsigned char COMRXPkgAnalysisCount;
	unsigned short COMRXPkgAnalysisModBusCRC16;
	unsigned short COMRXPkgAnalysisModBusCRC16Result;
	signed char COMRXPkgAnalysisResult;
	unsigned int COMRXPkgAnalysisFIFOOffset;

	unsigned char NewPkg;
	LCDPkg_S RXPkg;

}LCDProtocol_S;


/**
 * Initialize the TJC LCD packet transport protocol stack
 * \param LCDProtocol A pointer to the protocol stack structure
 * \return None
 */
void LCDProtocolInit(LCDProtocol_S* LCDProtocol);
/**
 * The LCDprotocol stack packet receives processing tasks
 * \param LCDProtocol A pointer to the protocol stack structure
 * \return None
 */
void LCDProtocolRXPkgAnalysisTask(LCDProtocol_S* LCDProtocol);
/**
 * Try to get a LCD packet received by the protocol stack(The key content of the packet is captured)
 * \param LCDProtocol A pointer to the protocol stack structure
 * \param LCDPkg A pointer to the packet data receive structure
 * \return Whether a packet was received (1-Yes 0-No)
 */
unsigned char LCDProtocolGetRXPkg(LCDProtocol_S* LCDProtocol, LCDPkg_S* LCDPkg);
/**
 * The received LCD data buffer is written to the protocol stack to receive the FIFO(hardware layer)
 * \param LCDProtocol A pointer to the protocol stack structure
 * \param Data A pointer that stores the received data to be written
 * \param Length The length of the received data to be written
 * \return Whether the data is written successfully (1-Yes 0-No)
 */ 
unsigned char LCDProtocolWriteRXFIFO(LCDProtocol_S* LCDProtocol, unsigned char* Data, unsigned int Length);
/**
 * The received LCD data byte is written to the protocol stack to receive the FIFO(hardware layer)
 * \param LCDProtocol A pointer to the protocol stack structure
 * \param Data A pointer that stores the received data to be written
 * \param Length The length of the received data to be written
 * \return Whether the data is written successfully (1-Yes 0-No)
 */ 
unsigned char LCDProtocolWriteRXFIFOByte(LCDProtocol_S* LCDProtocol, unsigned char* Data);

/**
 * Clear the LCD protocol stack receive buffer
 * \param LCDProtocol A pointer to the protocol stack structure
 * \return None
 */
void LCDProtocolFlushRXFIFO(LCDProtocol_S* LCDProtocol);

/**
 * Gets the LCD protocol readable length of the receive buffer
 * \param LCDProtocol A pointer to the protocol stack structure
 * \return Number of bytes
 */
unsigned int LCDProtocolGetRXFIFOReadSize(LCDProtocol_S* LCDProtocol);
/**
 * Gets the LCD protocol writable length of the receive buffer
 * \param LCDProtocol A pointer to the protocol stack structure
 * \return Number of bytes
 */
unsigned int LCDProtocolGetRXFIFOWriteSize(LCDProtocol_S* LCDProtocol);

#ifdef __cplusplus
}
#endif


#endif
