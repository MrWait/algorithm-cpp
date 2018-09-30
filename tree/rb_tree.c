#include "log.h"
#include "misc.h"
#define RED 0
#define BLACK 1

typedef struct _rbnode{
    int data;
    int color;
    struct _rbnode *l, *r, *p;
}rbnode, *prbtree;

int rbtree_insert(prbtree tree, int data)
{
    return 0;
}

int rbtree_delete(prbtree tree, int data)
{

}

rbnode *rbtree_search(prbtree tree, int data)
{
    return 0;
}

#define NUMBER 1000
void rbtree_test(void)
{
    rbnode n = {0, 0, NULL, NULL};
    int d1[ELEMENT_NUM], d2[ELEMENT_NUM], i;
    range(d1, ELEMENT_NUM, 1000, 10000);
    TS("Generate dat:");
    log_array(d1, ELEMENT_NUM);

    memcpy(d2, d1, sizeof(d1));
    for(i = 0; i < ELEMENT_NUM; i++)
    {
        rbtree_insert(&n, d2[i]);
    }
    AS;

    return 0;
}
