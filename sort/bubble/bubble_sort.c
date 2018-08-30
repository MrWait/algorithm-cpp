#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../lib/log/log.h"
#include <sys/time.h>
#define SWAP(a, b)                                      \
    do{int t_t = a;t_t = a; a = b; b = t_t; }while(0)   \

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

int bubble_sort(int array[], int len)
{
    int i, j, lc = 0, mc = 0, t;
    for(i = 0; i < len; i++)
    {
        for(j = 0; j < (len - i) - 1; j++)
        {
            lc++;
            if(array[j] > array[j + 1])
            {
                mc++;
                /* t = array[j]; */
                /* array[j] = array[j + 1]; */
                /* array[j + 1] = t; */
                SWAP(array[j], array[j + 1]);
            }
        }
    }
    /* TS("loop count: %d, move count: %d", lc, mc); */
    return 0;
}

void swap(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

int partition(int array[], int left, int right)
{
    int j = left;
    int i = j - 1;
    int key = array[right];
    for(; j < right; j++)
    {
        if(array[j] <= key)
        {
            swap(&array[j], &array[++i]);
        }
    }
    swap(&array[right], &array[++i]);
    return i;
}

void quicksort(int array[], int left, int right)
{
    int i, j, lc = 0, mc = 0;

    if(left >= right)
    {
        return;
    }

    int mid = partition(array, left, right);
    quicksort(array, left, mid - 1);
    quicksort(array, mid + 1, right);
}

void insertsort(int a[], int len)
{
    int t = 0;
    for(int i = 1; i < len; i++)
    {
        int j = i - 1;
        if(a[i] < a[j])
        {
            t = a[i];
            a[i] = a[j];
            while(t < a[j - 1])
            {
                a[j] = a[j - 1];
                j--;
            }
            a[j] = t;
        }
    }
}


void _insert_sort(int *a, int n, int dk)
{
    for(int i = dk; i < n; ++i)
    {
        int j = i - dk;
        if(a[i] < a[j])
        {
            int tmp = a[i];
            a[i] = a[j];
            while(a[j] > tmp)
            {
                a[j + dk] = a[j];
                j -= dk;
            }
            a[j + dk] = tmp;
        }
    }
}

void shellsort(int *a, int n)
{
    int dk = n / 2;
    while(dk >= 1)
    {
        _insert_sort(a, n, dk);
        dk /= 2;
    }
}

void selectsort(int *a, int n)
{
    for(int i = 0; i < n; i++)
    {
        int key = i;
        for(int j = i + 1; j < n; j++)
        {
            if(a[j] < a[key])
            {
                key = j;
            }
        }
        if(key != i)
        {
            SWAP(a[key], a[i]);
            /* int t; */
            /* TS("key: %d, i: %d", key, i); */
            /* t = a[key]; */
            /* a[key] = a[i]; */
            /* a[i] = t; */
        }
    }
}

void createheap(int *a, int i, int n)
{
    for(; i >= 0; i--)
    {
        int left = i * 2 + 1;
        int right = i * 2 + 2;
        int j = 0;
        if(right < n)
        {
            a[left] > a[right] ? (j = left) : (j = right);
        }else{
            j = left;
        }
        if(a[j] > a[i])
        {
            /* int tmp = a[i]; */
            /* a[i] = a[j]; */
            /* a[j] = tmp; */
            SWAP(a[i], a[j]);
        }
    }
}

void heapsort(int *a, int n)
{
    createheap(a, n / 2 - 1, n);
    for(int j = n - 1; j >= 0; j--)
    {
        /* int tmp = a[0]; */
        /* a[0] = a[j]; */
        /* a[j] = a[0]; */
        SWAP(a[0], a[j]);

        int i = j / 2 - 1;
        createheap(a, i, j);
    }
}

inline void merge(int *a, int left, int mid, int right)
{
    int len = right - left + 1;
    int *temp = (int*)malloc(sizeof(a[0]) * len);
    memset(temp, 0, sizeof(a[0]) * len);
    int k = 0;
    int i = left;
    int j = mid + 1;
    while(i <= mid && j <= right)
    {
        temp[k++] = ((a[i] <= a[j]) ? (a[i++]) : (a[j++]));
    }

    while(i <= mid)
    {
        temp[k++] = a[i++];
    }

    while(j <= right)
    {
        temp[k++] = a[j++];
    }
    for(int k = 0; k < len; k++)
    {
        a[left++] = temp[k];
    }
    free(temp);
}

void mergesort(int *a, int left, int right)
{
    if(left == right)
    {
        return;
    }

    int mid = (right + left) / 2;
    mergesort(a, left, mid);
    mergesort(a, mid + 1, right);
    merge(a, left, mid, right);
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

void log_array(int a[], int len)
{
    for(int i = 0; i < len; i++)
    {
        printf("%d\t", a[i]);
        if(i % 16 == 0)
        {
            printf("\r\n");
        }
    }
    printf("\r\n");
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

#define ARRAY_LEN 100
int main(void)
{
    int array[ARRAY_LEN];
    int array2[ARRAY_LEN];
    long i;
    range(array, ARRAY_LEN, ARRAY_LEN, ARRAY_LEN * 100);
    AS;
    memcpy(array2, array, sizeof(array));
    elapse(&i);
    bubble_sort(array2, ARRAY_LEN);
    TS("bubble_sort elaps %ld", elape(&i));
    log_array(array2, ARRAY_LEN);
    AS;
    memcpy(array2, array, sizeof(array));
    elapse(&i);
    quicksort(array2, 0, ARRAY_LEN - 1);
    TS("quicksort elaps %ld", elape(&i));
    log_array(array2, ARRAY_LEN);
    AS;
#if 1
    memcpy(array2, array, sizeof(array));
    elapse(&i);
    insertsort(array2, ARRAY_LEN);
    TS("insertsort elaps %ld", elape(&i));
    log_array(array2, ARRAY_LEN);
    AS;
#endif
#if 1
    memcpy(array2, array, sizeof(array));
    elapse(&i);
    shellsort(array2, ARRAY_LEN);
    TS("shellsort elaps %ld", elape(&i));
    log_array(array2, ARRAY_LEN);
    AS;
#endif
#if 1
    memcpy(array2, array, sizeof(array));
    elapse(&i);
    selectsort(array2, ARRAY_LEN);
    TS("selectsort elaps %ld", elape(&i));
    log_array(array2, ARRAY_LEN);
    AS;
#endif
#if 1
    memcpy(array2, array, sizeof(array));
    elapse(&i);
    heapsort(array2, ARRAY_LEN);
    TS("heapsort elaps %ld", elape(&i));
    log_array(array2, ARRAY_LEN);
    AS;
#endif
#if 1
    memcpy(array2, array, sizeof(array));
    elapse(&i);
    mergesort(array2, 0, ARRAY_LEN - 1);
    TS("mergesort elaps %ld", elape(&i));
    log_array(array2, ARRAY_LEN);
    AS;
#endif
    return 0;
}
