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
 * Function:String API interface function declaration.
 * Created on: 2015-05-17  the first version 
 */
#ifndef __STRING_H
#define __STRING_H 	

#ifdef __cplusplus
extern "C" {
#endif


/**
 * Get string length
 * \param Str String pointer
 * \return String Length Value
 */
unsigned int StrLen(const char* Str);

/**
 * String copy
 * \param Dest Destination String pointer
 * \param Src  Source String pointer
 * \return Destination string pointer value
 */
char* StrCopy(char* Dest, const char* Src);

/**
 * String copy safety
 * \param Dest Destination String pointer
 * \param Src  Source String pointer
 * \param MaxLength  Destination string maximum writable length
 * \return Destination string pointer value
 */
char* StrCopySafe(char* Dest, const char* Src, unsigned int MaxLength);

/**
 * String comparison
 * \param Dest String pointer
 * \param Src  String pointer
 * \return Whether the contents of the two strings are the same (1-Yes 0-No)
 */
unsigned char StrCmp(const char* Src, const char* Dest);

/**
 * Concatenate one string onto another string
 * \param Dest Destination string pointer
 * \param Src  Source String pointer
 * \return Destination string pointer value
 */
char* StrCat(char* Dest,const char* Src);

/**
 * Concatenate one string onto another string safety
 * \param Dest Destination string pointer
 * \param Src  Source String pointer
 * \param MaxLength  Destination string maximum writable length
 * \return Destination string pointer value
 */
char* StrCatSafe(char* Dest,const char* Src,unsigned int MaxLength);

/**
 * Concatenate one character onto the string
 * \param Dest Destination string pointer
 * \param Character one character
 * \return Destination string pointer value
 */
char* StrCatChar(char* Dest,char Character);

/**
 * Remove one character from the string tail
 * \param Dest Destination string pointer
 * \return Destination string pointer value
 */
char* StrRemoveTailChar(char* Dest);

/**
 * Finds the starting position of a string of characters from a string
 * \param Str A pointer to the string
 * \param Pattern Pointer to the string to match
 * \return The starting index position of the match (-1 Failed to match)
 */
signed int StrIndex(const char* Str, const char* Pattern);

/**
 * Finds the starting position of a string of characters from a string safety
 * \param Str A pointer to the string
 * \param Pattern Pointer to the string to match
 * \param MaxSearchLength The maximum length of a string that can be search
 * \return The starting index position of the match (-1 Failed to match)
 */
signed int StrIndexSafe(const char* Str,const char* Pattern,unsigned int MaxSearchLength);

/**
 * Finds the starting position of a string of characters from a string safety
 * \param Str A pointer to the string
 * \param Pattern character to match
 * \return The starting index position of the match (-1 Failed to match)
 */
signed int StrIndexChar(const char* Str, char Pattern);
/**
 * String match
 * \param Str1 String pointer
 * \param Str2  String pointer
 * \return Whether the contents of the two strings are the same (1-Yes 0-No)
 */
unsigned char StrMatch(const char* Str1, const char* Str2);

/**
 * Convert a string to an double (unsafety)
 * \param Str The string to be converted
 * \return Returns the double result of the conversion
 */
double StrToDouble(char* Str);

/**
 * Converts an integer to a hexadecimal string
 * \param Str A string pointer that receives the result of the conversion
 * \return Whether the conversion is successful (1-Yes 0-No)
 */
signed int StrToIntHex(char* Str);

/**
 * Trying to convert a string to an int32 value
 * \param Str The string to be converted
 * \param Value A int32 pointer that receives the result of the conversion
 * \return Whether the conversion is successful (1-Yes 0-No)
 */
unsigned char StrTryToInt(char* Str,int* Value);
/**
 * Trying to convert a string to an float value
 * \param Str The string to be converted 
 * \param Value A float pointer that receives the result of the conversion
 * \return Whether the conversion is successful (1-Yes 0-No)
 */
unsigned char StrTryToFloat(char* Str,float* Value);
/**
 * Trying to convert a string to an double value
 * \param Str The string to be converted
 * \param Value A double pointer that receives the result of the conversion
 * \return Whether the conversion is successful (1-Yes 0-No)
 */
unsigned char StrTryToDouble(char* Str,double* Value);




#ifdef __cplusplus
}
#endif

#endif
