// Digital Search Tree (DST) impl

typedef struct _node {
  char key[3];
  struct __node *l;
  struct __node *r;
} node_t;
