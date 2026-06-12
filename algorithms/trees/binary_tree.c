#include <stdlib.h>

typedef struct _Item {
  int key;
} Item;

typedef struct node {
  Item item;
  struct node *l;
  struct node *r;
} link;

link *btree_init() {
  link *node = malloc(sizeof(link));
  node->item.key = 0;
  node->l = NULL;
  node->r = NULL;
  return node;
}

int main(void) {
  link *node = btree_init();

  return 0;
}
