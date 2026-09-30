// tries impl.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int bit(const char *key, int w) {
  unsigned char c = (unsigned char)key[w / 8];
  int shift = 7 - (w % 8);
  return (c >> shift) & 1;
}

node_t *split(node_t *p, node_t *node, int w) {
  node_t *null_node = tries_init();
  switch (bit(p->key, w) * 2 + bit(node->key, w)) {
  case 0:
    null_node->l = split(p, node, w + 1);
    break;

  case 1:
    null_node->l = p;
    null_node->r = node;
    break;

  case 2:
    null_node->r = p;
    null_node->l = node;
    break;

  case 3:
    null_node->r = split(p, node, w + 1);
    break;
  }
  return null_node;
}

node_t *tries_insert_recurs(node_t *root, node_t *node, int w) {
  int b = bit(node->key, w);
  if (!root || (root->key == NULL && root->l == NULL && root->r == NULL))
    return node;

  if (root->l == NULL && root->r == NULL) {
    return split(root, node, w);
  }

  if (b > 0)
    root->r = tries_insert_recurs(root->r, node, w + 1);
  else
    root->l = tries_insert_recurs(root->l, node, w + 1);

  return root;
}

node_t *tries_insert(node_t *root, char *key) {
  node_t *node = malloc(sizeof(node_t));
  node->key = strdup(key);
  node->l = node->r = NULL;
  return tries_insert_recurs(root, node, 0);
}

node_t *tries_search_recurs(node_t *root, const char *key, int w) {
  int b = bit(key, w);

  if (!root)
    return NULL;

  if (root->l == NULL && root->r == NULL) {
    if (root->key != NULL && strcmp(root->key, key) == 0)
      return root;

    return NULL;
  }

  if (b > 0)
    return tries_search_recurs(root->r, key, w + 1);
  else
    return tries_search_recurs(root->l, key, w + 1);
}

node_t *tries_search(node_t *root, char *key) { return tries_search_recurs(root, key, 0); }

int main(void) {
  node_t *root = tries_init();
  root = tries_insert(root, "hey");
  root = tries_insert(root, "hello");
  root = tries_insert(root, "tiger");
  root = tries_insert(root, "milo");
  root = tries_insert(root, "zebra");

  node_t *node = tries_search(root, "milo");
  printf("%s\n", node->key);

  return 0;
}
