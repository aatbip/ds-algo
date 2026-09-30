// tries impl.

#include <stdlib.h>
typedef struct _node {
  char *key;
  struct _node *l;
  struct _node *r;
} node_t;

node_t *tries_init() {
  node_t *root = malloc(sizeof(node_t));
  root->l = root->r = NULL;
  root->key = NULL;
  return root;
}
