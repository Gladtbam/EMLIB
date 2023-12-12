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
 * Function:Array API interface function declaration.
 * Created on: 2015-01-19  the first version 
 */

#ifndef __ARRAY_H
#define __ARRAY_H 	

#ifdef __cplusplus
extern "C" {
#endif

/**
 * The array is initialized with a specific value
 * \param Buffer array pointer to initialize
 * \param Length array length
 * \param Value  A value array to be initialized to
 * \return None
 */
void ArrayInit(void* const Buffer, unsigned int Length, unsigned char Value);
/**
 * Copy between arrays
 * \param Dest        Pointer to the array to copy to
 * \param DestIndex   Offset of the destination array
 * \param Source      Pointer to the array to copy from
 * \param SourceIndex Offset of the source array
 * \param Length      Length to copy
 * \return Pointer to the destination array
 */
void* ArrayCopy(void* Dest, unsigned int DestIndex, const void* Source, unsigned int SourceIndex, unsigned int Length);
/**
 * Determines whether the contents of the two arrays match exactly
 * \param Source1   Pointer to the array1 to be matched
 * \param Source2   Pointer to the array2 to be matched
 * \param Length    Length to match
 * \return Whether it is an exact match (1 Yes 0 No)
 */
unsigned char ArrayMatch(const void* Source1, const void* Source2, unsigned int Length);

#ifdef __cplusplus
}
#endif

#endif













