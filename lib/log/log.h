#ifndef __LOG_H__
#define __LOG_H__
#include <stdio.h>
#include <stdlib.h>

#define _STR(x) _VAL(x)
#define _VAL(x) #x
#define AS printf("  [ %s ] ( " _STR(__LINE__) " )\r\n", __func__)
#define TS(f,a...) printf(" [ %s ] ( " _STR(__LINE__) " ) : " f "\r\n", __func__, ##a)

#endif  /* __LOG_H__ */
