#ifndef __MISC_H__
#define __MISC_H__
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SWAP(a, b)                                      \
    do{int t_t = a;t_t = a; a = b; b = t_t; }while(0)   \

long systime(void);
long systime_ms(void);
long systime_us(void);
int _rand(int l, int h);
void range(int data[], int len, int b, int top);
void elapse(long *t);
long elape(long *t);
#endif  /* __MISC_H__ */
