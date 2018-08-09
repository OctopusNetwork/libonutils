#ifndef __RBTREE_API____H__
#define __RBTREE_API____H__

#include "rbtree.h"

typedef enum {
    N_CMP_EQUAL,
    N_CMP_LOWER,
    N_CMP_LARGER
} rbtree_cmpresult_e_t;

typedef rbtree_cmpresult_e_t (*rbtree_compare_f_t)
    (struct rb_node *n1, struct rb_node *n2);

#ifdef __cplusplus
extern "C" {
#endif

void rbtree_insert(struct rb_root *root, struct rb_node *node,
        rbtree_compare_f_t compare);
void rbtree_erase(struct rb_root *root, struct rb_node *node);

#ifdef __cplusplus
}
#endif

#endif
