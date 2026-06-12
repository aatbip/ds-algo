
typedef struct _Item {
  int key;
} Item;

typedef struct node {
  Item item;
  struct node *l;
  struct node *r;
} link;
