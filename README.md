# EMLIB (New version)
C language implementation of embedded common software components tools library.
## Update Description
EMLIB created the first version of the library in 2015.It has been continuously updated since 2015.Because there were too many historical versions, a new repository was created to store them.The previous repository has been deleted.
## Whether to consider open source?
EMLIB is not an open source project. If you have comments or suggestions, please open issue.
## Module detail description
### Array.h
Includes array initialization, comparison, and fast copy.
### Color.h
Includes color gamut conversion functions for colors.
### DateTime.h
Includes date and timestamp conversions, date interval time, and UTC support.
### DigitalFilter.h
Includes low-pass filter, peak-to-peak filter and Kalman filter.
### FIFO.h
Includes FIFO read and write operations, supports simultaneous multithreaded access by consumers and producers.
### Hash.h
Includes CRC series calculation functions and MD5 calculation functions.
### LCDProtocol.h
A customizable universal communication protocol that includes the TJC serial screen for receiving on-screen keys or messages.
### PID.h
Includes discrete PID caculate function and parameter setting method.
### PkgProtocol.h
Includes a customizable packet header of the sending and receiving protocol stack, support variable length protocol packets support UART, CAN, etc.
### PrintfLib.h
The printf library function is completely rewritten, which reduces the stack utilization rate and improves the stability of embedded system.
### Stopwatch.h
A stopwatch assembly for rough non-blocking timing.
### String.h
Overrode some of the methods in the string library, added some conversions between numbers and strings
### Copyright (c) 2015-Now, Gladtbam.
