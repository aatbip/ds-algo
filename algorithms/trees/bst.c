typedef struct _bst_node {
  int key;
  struct _bst_node *l;
  struct _bst_node *r;
} bst_node_t;

typedef struct _bst_ctx {
  bst_node_t root;
  int count; // number of nodes
} bst_ctx;
