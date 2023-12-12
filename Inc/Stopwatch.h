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
 * Function:Stopwatch API interface function declaration.
 * Created on: 2015-04-11  the first version 
 */
#ifndef __STOPWATCH_H
#define __STOPWATCH_H 	

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
	unsigned long long StartValue;
}
Stopwatch_S;


/**
 * Initialize the stopwatch module
 * \param RefTime A pointer to the 64bit time base (1xs Tick)
 * \return None
 */
void StopwatchInit(unsigned long long * RefTime);

/**
 * Start the stopwatch timer
 * \param Stopwatch A pointer to the stopwatch structure
 * \return None
 */
void StopwatchStart(Stopwatch_S* Stopwatch);

/**
 * Gets the time elapsed from the start of the stopwatch to when this function is called(It doesn't stop the stopwatch)
 * \param Stopwatch A pointer to the stopwatch structure
 * \return Elapsed time(xs)
 */
unsigned long long StopwatchStop(Stopwatch_S* Stopwatch);

/**
 * Gets the time elapsed from the start of the stopwatch to when this function is called(This changes the time the stopwatch starts to the time the function is called)
 * \param Stopwatch A pointer to the stopwatch structure
 * \return Elapsed time(xs)
 */
unsigned long long StopwatchTimeSpan(Stopwatch_S* Stopwatch);


#ifdef __cplusplus
}
#endif


#endif

























