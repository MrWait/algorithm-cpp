#include "avl_tree.h"
#include "log.h"
#include "misc.h"

#define EH 0
#define LH 1
#define RH -1

typedef sturct _node
{
    int data;
    int bf;
    struct _node *l, *r;
}node, *tree;

int avl_insert(tree t, )
{
    return 0;
}

int avl_delete(tree t, int data)
{

}

int avl_search(tree t, int data)
{

}

#define ELEMENT_NUM 100
int avl_tree_test(void)
{
    node n = {0, 0, NULL, NULL};
    int d1[ELEMENT_NUM], d2[ELEMENT_NUM], i;
    range(d1, ELEMENT_NUM, 1000, 10000);
    TS("Generate dat:");
    log_array(d1, ELEMENT_NUM);

    memcpy(d2, d1, sizeof(d1));
    for(i = 0; i < ELEMENT_NUM; i++)
    {
        avl_insert(&n, d2[i]);
    }
    AS;

    return 0;
}
