// Digital Search Tree (DST) impl
#include "stdlib.h"
#include <stdlib.h>
#include <string.h>

typedef struct _node {
  char key[3];
  struct __node *l;
  struct __node *r;
} node_t;

// returns root node
node_t *dst_init() {
  node_t *root = malloc(sizeof(*root));
  root->l = root->r = NULL;
  strcpy(root->key, NULL);
  return root;
}
