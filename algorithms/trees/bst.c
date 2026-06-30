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
bst_node_t *bst_init() {
  bst_node_t *root = malloc(sizeof(bst_node_t));
  root = NULL;

  // initialize bst_ctx
  bst_ctx.count = 0;
  bst_ctx.root = root;

  return root;
}

void int_insert(bst_node_t *node, bst_node_t *parent) {
  if (parent == NULL) {
    if (node->key < parent->key) {
      parent->l = node;
    } else {
      parent->r = node;
    }
    return;
  }
  if (node->key > parent->key) {
    int_insert(node, parent->r);
  } else {
    int_insert(node, parent->l);
  }
}

void bst_insert(int key) {
  if (bst_ctx.root == NULL) {
    bst_ctx.root->key = key;
    bst_ctx.root->l = NULL;
    bst_ctx.root->r = NULL;
    return;
  }

  bst_node_t *node = malloc(sizeof(bst_node_t));
  node->key = key;
  node->l = NULL;
  node->r = NULL;
  int_insert(node, bst_ctx.root);
}
