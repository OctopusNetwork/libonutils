#include <linux/random.h>

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>

#include "libonutils/rbtree_api.h"

#define NODES       100
// #define PERF_LOOPS  100000
#define PERF_LOOPS  1
#define CHECK_LOOPS 100

typedef struct {
    uint32_t key;
    struct rb_node rb;
} test_node_s_t;

static struct rb_root root = RB_ROOT;
static test_node_s_t nodes[NODES];

static rbtree_cmpresult_e_t __compare(struct rb_node *n1, struct rb_node *n2)
{
    test_node_s_t *tn1 = container_of(n1, test_node_s_t, rb);
    test_node_s_t *tn2 = container_of(n2, test_node_s_t, rb);

    if (tn1->key < tn2->key) {
        return N_CMP_LOWER;
    } else {
        return N_CMP_LARGER;
    }

    return N_CMP_LOWER;
}

static void dump_rbtree(struct rb_root *root)
{
    struct rb_node *rb;

    for (rb = rb_first(root); rb; rb = rb_next(rb)) {
        test_node_s_t *parent;
        parent = rb_entry(rb, test_node_s_t, rb);
        printf("key %u\n", parent->key);
    }
}

static void init(void)
{
    int i;
    for (i = 0; i < NODES; i++) {
        nodes[i].key = rand();
    }
}

int main(int argc, char *argv[])
{
    int j;

    init();

    for (j = 0; j < NODES; j++)
        rbtree_insert(&root, &nodes[j].rb, __compare);

    dump_rbtree(&root);

    for (j = 0; j < NODES; j++)
        rbtree_erase(&root, &nodes[j].rb);

    return 0;
}
