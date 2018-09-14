#include "log.h"

void log_array(int a[], int len)
{
    for(int i = 0; i < len; i++)
    {
        printf("%d\t", a[i]);
        if((i + 1) % 16 == 0)
        {
            printf("\r\n");
        }
    }
    printf("\r\n");
}
