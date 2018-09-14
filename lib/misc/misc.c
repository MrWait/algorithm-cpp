#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "misc.h"
#include <sys/time.h>

long systime(void)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec;
}

long systime_ms(void)
{
    struct timeval tv;
    long r;
    gettimeofday(&tv, NULL);
    r = tv.tv_sec * 1000 + tv.tv_usec / 1000;
    return r;
}

long systime_us(void)
{
    struct timeval tv;
    long r;
    gettimeofday(&tv, NULL);
    r = tv.tv_sec * 1000000 + tv.tv_usec;
    return r;
}

int _rand(int l, int h)
{
    return rand() % (h - l) + l;
}

void range(int data[], int len, int b, int top)
{
    int i, p = 1324;
    srand(systime_ms());
    for(i = 0; i < len; i++)
    {
        data[i] = _rand(b, top);
        /* p = data[i] + 1; */
    }
}

void elapse(long *t)
{
    *t = systime_us();
}

long elape(long *t)
{
    long n = systime_us() - *t;
    return n;
}
