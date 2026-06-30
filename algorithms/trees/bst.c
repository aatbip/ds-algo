#include <stdlib.h>

typedef struct _bst_node {
  int key;
  struct _bst_node *l;
  struct _bst_node *r;
} bst_node_t;

typedef struct _bst_ctx {
  bst_node_t *root; // root node
  int count;        // number of nodes
} bst_ctx_t;

static bst_ctx_t bst_ctx;

/*init() create a dummy root*/
bst_node_t *init() {
  bst_node_t *root = malloc(sizeof(bst_node_t));
  root = NULL;

  // initialize bst_ctx
  bst_ctx.count = 0;
  bst_ctx.root = root;

  return root;
}
