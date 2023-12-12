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
 * Function:PID API interface function declaration.
 * Created on: 2015-08-09  the first version 
 */
#ifndef __PID_H
#define __PID_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
 float P,I,D;
 float OP,OI,OD;
 float Error;
 float Integral;
 float LastError;
 float Output;
 float IntegralMax;
 float IntegralMin;
 

}
PID_S;

/**
 * Discrete PID calculation core
 * \param PID A pointer to the PID structure
 * \param Expect PID target expected value
 * \param Actual PID target actual  value
 * \return PID caculate output value
 */
float PIDCalculate(PID_S* PID,float Expect,float Actual);
/**
 * PID Parameter ZieglerNichols setting method
 * \param PID A pointer to the PID structure
 * \param T   PID T value
 * \param Kc  PID Kc value
 * \param Pc  PID Pc value
 * \return None
 */
float PIDZieglerNicholsPID(PID_S* PID,float T,float Kc,float Pc);






#ifdef __cplusplus
}
#endif



#endif

