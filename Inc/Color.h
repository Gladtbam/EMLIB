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
 * Function:Color Convert API interface function declaration.
 * Created on: 2015-02-18  the first version 
 */

#ifndef __COLOR_H
#define __COLOR_H

#ifdef __cplusplus
extern "C" {
#endif



typedef struct
{
	float H;//(0-360.0)
	float S;//(0-1.0)
	float V;//(0-1.0)
	unsigned int RGB;//RGB888(0x000000-0xFFFFFF)
}Color_S;

/**
 * Convert a color value from RGB888 to HSV
 * \param FIFO A pointer to the Color structure
 * \return None
 */
void ColorRGBToHSV(Color_S* Color);
/**
 * Convert a color value from HSV to RGB888
 * \param FIFO A pointer to the Color structure
 * \return None
 */
void ColorHSVToRGB(Color_S* Color);



#ifdef __cplusplus
}
#endif

#endif


