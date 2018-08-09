#include "rbtree.h"

#include "rbtree_api.h"

void rbtree_insert(struct rb_root *root, struct rb_node *node,
        rbtree_compare_f_t compare)
{
    struct rb_node **new = &root->rb_node;
    struct rb_node *parent = NULL;

    while (*new) {
        parent = *new;
        if (N_CMP_LOWER == compare(node, parent)) {
            new = &parent->rb_left;
        } else {
            new = &parent->rb_right;
        }
    }

    rb_link_node(node, parent, new);
    rb_insert_color(node, root);
}

void rbtree_erase(struct rb_root *root, struct rb_node *node)
{
    rb_erase(node, root);
}
