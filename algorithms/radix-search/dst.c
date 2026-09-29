// Digital Search Tree (DST) impl

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node {
  char *key;
  struct _node *l;
  struct _node *r;
} node_t;

// returns root node
node_t *dst_init() {
  node_t *node = NULL;
  return node;
}

int bit(const char *key, int w) {
  unsigned char c = (unsigned char)key[w / 8];
  int shift = 7 - (w % 8);
  return (c >> shift) & 1;
}

node_t *dst_insert_recurs(node_t *root, node_t *node, int w) {
  if (!root)
    return node;
  int b = bit(node->key, w);
  if (b > 0) {
    root->r = dst_insert_recurs(root->r, node, w + 1);
  } else {
    root->l = dst_insert_recurs(root->l, node, w + 1);
  }
  return root;
}

node_t *dst_insert(node_t *root, char *key) {
  node_t *node = malloc(sizeof(*node));
  node->key = strdup(key);
  node->l = node->r = NULL;
  return dst_insert_recurs(root, node, 0);
}

node_t *dst_search_recurse(node_t *root, const char *key, int w) {
  if (!root)
    return NULL;
  if (strcmp(root->key, key) == 0)
    return root;
  int b = bit(key, w);
  if (b > 0) {
    return dst_search_recurse(root->r, key, w + 1);
  } else {
    return dst_search_recurse(root->l, key, w + 1);
  }
}

node_t *dst_search(node_t *root, char *key) { return dst_search_recurse(root, key, 0); }

int main(void) {
  node_t *root = dst_init();
  root = dst_insert(root, "hello");
  root = dst_insert(root, "hey");
  root = dst_insert(root, "apple");
  root = dst_insert(root, "ball");
  root = dst_insert(root, "cat");
  root = dst_insert(root, "dog");
  root = dst_insert(root, "milo");
  root = dst_insert(root, "tiger");
  root = dst_insert(root, "ktm");
  root = dst_insert(root, "city");
  node_t *node = dst_search(root, "ktm");
  printf("%s\n", node->key);
  node = dst_search(root, "apple");
  printf("%s\n", node->key);
  node = dst_search(root, "tiger");
  printf("%s\n", node->key);
  node = dst_search(root, "milo");
  printf("%s\n", node->key);
  node = dst_search(root, "city");
  printf("%s\n", node->key);
  return 0;
}
