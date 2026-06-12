#include <stdlib.h>

typedef struct _Item {
  int key;
} Item;

typedef struct node {
  Item item;
  struct node *l;
  struct node *r;
} link;

link *btree_init(int key) {
  link *node = malloc(sizeof(link));
  node->item.key = key;
  node->l = NULL;
  node->r = NULL;
  return node;
}

int main(void) {
  link *node = btree_init(1);

  return 0;
}
