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
 * Function:DigitalFilter API interface function declaration.
 * Created on: 2015-05-17  the first version 
 */
#ifndef __DIGITALFILTER_H
#define __DIGITALFILTER_H 	

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
 float LastOutput;
 float Suppression;//(0-1)The larger the coefficient of variation amplitude, the closer it is to the actual value
}
DigitalFilterLPF_S;

typedef struct
{
 float LastOutput;
 float PeakHigh;//Hith peak limiting
 float PeakLow;//Low peak limiting
}
DigitalFilterPPF_S;


typedef struct
{
 float B;
 float Q;
 float R;
 
 float XHat;
 float P;
 
 float XHat_;
 float P_;
 float K;
}
DigitalFilterKalman_S;


/**
 * Digital low-pass filter calculation(Reduces the real-time rate of change of values)
 * \param LPF A pointer to the low-pass filter structure
 * \param Value  The value to be filtered
 * \return The value after filtering
 */
float DigitalFilterLPF(DigitalFilterLPF_S* LPF,float Value);
/**
 * Digital peak-peak filter calculation(When the value exceeds the peak value, the last output value is maintained)
 * \param LPF A pointer to the peak-peak filter structure
 * \param Value  The value to be filtered
 * \return The value after filtering
 */
float DigitalFilterPPF(DigitalFilterPPF_S* PPF,float Value);
/**
 * Kalman digital filter(The value measured by the sensor can be stable and reliable)
 * \param Z Observed Actual value 
 * \param U Controlled quantity
 * \return The value after filtering
 */
float DigitalFilterKalman(DigitalFilterKalman_S* Kalman,float Z,float U);



#ifdef __cplusplus
}
#endif

#endif
