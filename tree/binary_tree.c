#include "binary_tree.h"
#include "log.h"
#include "misc.h"

int btree_add_node(b_node *head, b_node *node)
{
    if(node->data > head->data)
    {
        if(head->r == NULL)
        {
            head->r = node;
        }else{
            btree_add_node(head->r, node);
        }
    }else{
        if(head->l == NULL)
        {
            head->l = node;
        }else{
            btree_add_node(head->l, node);
        }
    }
    return 0;
}

int btree_add_data(b_node *head, int data)
{
    b_node *node = calloc(1, sizeof(b_node));
    if(node)
    {
        node->data = data;
    }
    if(head->l == NULL)
    {
        head->l = node;
        return 0;
    }
    return btree_add_node(head->l, node);
}

b_node *btree_search_data(b_node *head, int data)
{
    b_node *c;
    if(head == NULL || head->l == NULL)
    {
        return NULL;
    }
    c = head->l;
    while(c)
    {
        if(data == c->data)
        {
            return c;
        }
        if(data > c->data && c->r)
        {
            c = c->r;
        }else if(data < c->data && c->l)
        {
            c = c->l;
        }else{
            return NULL;
        }
    }
    return NULL;
}

void btree_delete_data(b_node *head, int data)
{
    b_node *c, *remain, *p = head;
    int d = 1;                  /* direction of current node to parent */
    if(!head || !head->l)
    {
        return NULL;
    }
    c = head->l;
    while(c)
    {
        if(data == c->data)
        {
            break;
        }
        if(data > c->data)
        {
            d = 2;
            p = c;
            c = c->r;
        }else if(data < c->data)
        {
            d = 1;
            p = c;
            c = c->l;
        }
    }
    if(c == NULL)
    {
        /* not found */
        TS("not found");
        return;
    }

    /* left orient */
    remain = c->r;
    if(d == 2)
    {
        p->r = c->l;
    }

    if(d == 1)
    {
        p->l = c->l;
    }

    c = p;
    while(c)
    {
        if(remain->data > c->data)
        {
            c = c->r;
        }
        else if(remain->data <= p->data)
        {
            p = p->l;
        }
    }

    /* btree_add_node(p, remain); */
}

int btree_show_clr(b_node *head)
{
    if(!head)
    {
        return 0;
    }

    printf("%d\t", head->data);
    if(head->l)
    {
        btree_show_clr(head->l);
    }
    if(head->r)
    {
        btree_show_clr(head->r);
    }
}

int btree_show_lcr(b_node *head)
{
    if(!head)
    {
        return 0;
    }

    if(head->l)
    {
        btree_show_clr(head->l);
    }
    printf("%d\t", head->data);
    if(head->r)
    {
        btree_show_clr(head->r);
    }
}

int btree_show_lrc(b_node *head)
{
    if(!head)
    {
        return 0;
    }

    if(head->l)
    {
        btree_show_clr(head->l);
    }
    if(head->r)
    {
        btree_show_clr(head->r);
    }
    printf("%d\t", head->data);

}

static int _btree_height(b_node *head, int d)
{
    int l = 0, r = 0;
    if(!head)
    {
        return d;
    }
    l = _btree_height(head->l, d + 1);
    r = _btree_height(head->r, d + 1);
    return l > r ? l : r;
}

int btree_height(b_node *head)
{
    return _btree_height(head->l, 0);
}

b_node *btree_min(b_node *head)
{
    b_node *min;
    if(head->l == NULL)
    {
        return NULL;
    }
    min = head->l;
    while(min->l)
    {
        min = min->l;
    }
    return min;
}

b_node *btree_max(b_node *head)
{
    b_node *min;
    if(head->l == NULL)
    {
        return NULL;
    }
    min = head->l;
    while(min->r)
    {
        min = min->r;
    }
    return min;
}

int btree_empty(b_node *head)
{
    return head->l == NULL;
}

#define ELEMENT_NUM 100

int btree_test(void)
{
    int d1[ELEMENT_NUM], d2[ELEMENT_NUM], i;
    b_node tree = {0, NULL, NULL}, *t;
    range(d1, ELEMENT_NUM, 1000, 10000);
    TS("generate data:");
    log_array(d1, ELEMENT_NUM);

    memcpy(d2, d1, sizeof(d1));
    for(i = 0; i < ELEMENT_NUM; i++)
    {
        btree_add_data(&tree, d2[i]);
    }
    AS;
    btree_show_clr(&tree);
    AS;
    btree_show_lcr(&tree);
    AS;
    btree_show_lrc(&tree);
    AS;
    t = btree_min(&tree);
    if(t)
    {
        TS("tree min data: %d", t->data);
    }
    AS;
    TS("tree height: %d", btree_height(&tree));
    AS;
    t = btree_max(&tree);
    if(t)
    {
        TS("tree max data: %d", t->data);
    }
    AS;
    btree_empty(&tree);
    AS;
    t = btree_search_data(&tree, d2[21]);
    if(t)
    {
        TS("tree search got: %d", t->data);
    }else
    {
        TS("tree not find");
    }
    AS;
    t = btree_search_data(&tree, 10100);
    if(t)
    {
        TS("tree search got: %d", t->data);
    }else
    {
        TS("tree not find");
    }
    AS;
    for(i = 0; i < ELEMENT_NUM; i++)
    {
        btree_delete_data(&tree, d2[i]);
    }
    return 0;
}
