#include <stdio.h>
#include <stdlib.h>

typedef struct _bst_node {
  int key;
  struct _bst_node *l;
  struct _bst_node *r;
} bst_node_t;

typedef struct _bst_ctx {
  int count; // number of nodes
} bst_ctx_t;

static bst_ctx_t bst_ctx;

/*init() create a dummy root*/
bst_node_t *bst_init() {
  // initialize bst_ctx
  bst_ctx.count = 0;

  return NULL;
}

bst_node_t *int_insert(bst_node_t *node, bst_node_t *parent) {
  if (parent == NULL) {
    return node;
  }
  if (node->key > parent->key) {
    parent->r = int_insert(node, parent->r);
  } else {
    parent->l = int_insert(node, parent->l);
  }
  return parent;
}

bst_node_t *bst_insert(bst_node_t *root, int key) {
  bst_node_t *node = malloc(sizeof(bst_node_t));
  node->key = key;
  node->l = node->r = NULL;

  if (root == NULL) {
    return node;
  }

  return int_insert(node, root);
}

// preorder traversal (DFS)
void pre_traverse(bst_node_t *node) {
  if (!node)
    return;
  printf("%d\n", node->key);
  pre_traverse(node->l);
  pre_traverse(node->r);
}

int main(void) {
  bst_node_t *root = bst_init();
  root = bst_insert(root, 20);
  root = bst_insert(root, 19);
  root = bst_insert(root, 25);

  pre_traverse(root);
  return 0;
}
