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
 * Function:DateTime API interface function declaration.
 * Created on: 2015-12-08  the first version 
 */
#ifndef __DATETIME_H
#define __DATETIME_H 	

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
  signed char UTC;//Must Set the Value
  //
  unsigned int TimeStamp;
  //
  unsigned short Year;  
  unsigned char Month;  
  unsigned char Day;
  unsigned char Hour;     
  unsigned char Minute;  
  unsigned char Second;  
  //
  unsigned char DayOfWeek;//Auto Create
  
}DateTime_S;


/**
 * Create a DateTime structure from date(Need:UTC Year Month Day Hour Minute Second)
 * \param DateTime A pointer to the DateTime structure
 * \return Whether successfully created(1-Yes 0-No)
 */
unsigned char DateTimeCreateFromDate(DateTime_S* DateTime);

/**
 * Create a DateTime structure from TimeStamp(Need:UTC TimeStamp)
 * \param DateTime A pointer to the DateTime structure
 * \return Whether successfully created(1-Yes 0-No)
 */
unsigned char DateTimeCreateFromTimeStamp(DateTime_S* DateTime);

/**
 * Gets the time interval between two dates(s)
 * \param DateTimeStart A pointer to the Start DateTime structure
 * \param DateTimeEnd A pointer to the End DateTime structure
 * \return Time interval of seconds
 */
unsigned int DateTimeGetTimeSpan(DateTime_S* DateTimeStart,DateTime_S* DateTimeEnd);

/**
 * Check whether the DateTime_S structure is valid
 * \param DateTime A pointer to the DateTime structure
 * \return Whether the value is valid(1-Yes 0-No)
 */
unsigned char DateTimeDateIsValid(DateTime_S* DateTime);

/**
 * Gets the number of days in a specified month in a specified year
 * \param Year The year to specify
 * \param Month The month to specify
 * \return The maximum number of days in a month
 */
unsigned char DateTimeGetMonthMaxDay(unsigned short Year,unsigned char Month);

/**
 * Determines whether the specified year is a leap year
 * \param Year The year to specify
 * \return Whether it is a leap year(1-Yes 0-No)
 */
unsigned char DateTimeIsLeapYear(unsigned short Year);










#ifdef __cplusplus
}
#endif


#endif
