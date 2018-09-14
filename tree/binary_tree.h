#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__
typedef struct _b_node{
    int data;
    struct _b_node *l, *r;
}b_node;

int btree_add_node(b_node *head, b_node *node);
int btree_show_clr(b_node *head);
int btree_show_lcr(b_node *head);
int btree_show_lrc(b_node *head);
int btree_height(b_node *head);
b_node *btree_min(b_node *head);
b_node *btree_max(b_node *head);
int btree_empty(b_node *head);

#endif  /* __BINARY_TREE_H__ */
