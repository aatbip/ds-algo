#include <stdio.h>
#include <stdlib.h>

typedef struct _Item {
  int key;
} Item;

typedef struct node {
  Item item;
  struct node *l;
  struct node *r;
} link;

typedef struct {
  link *q[256];
  int dq_idx;
  int eq_idx;
  int size;
} queue;

// preorder traversal
void pre_traverse(link *node) {
  if (!node)
    return;
  printf("%d\n", node->item.key);
  pre_traverse(node->l);
  pre_traverse(node->r);
}
// inorder traversal
void inorder_traverse(link *node) {
  if (!node)
    return;
  inorder_traverse(node->l);
  printf("%d\n", node->item.key);
  inorder_traverse(node->r);
}
// postorder traversal
void post_traverse(link *node) {
  if (!node)
    return;
  post_traverse(node->l);
  post_traverse(node->r);
  printf("%d\n", node->item.key);
}

// level traversal
void level_traverse(link *node) {
  queue q = {0, .size = 256};

  q.q[q.eq_idx++ % q.size] = node;

  while (q.dq_idx != q.eq_idx) {
    link *curr = q.q[q.dq_idx++ % q.size];
    printf("%d\n", curr->item.key);
    if (curr->l)
      q.q[q.eq_idx++ % q.size] = curr->l;
    if (curr->r)
      q.q[q.eq_idx++ % q.size] = curr->r;
  }
}

link *btree_create_node(int key) {
  link *node = malloc(sizeof(link));
  node->item.key = key;
  node->l = NULL;
  node->r = NULL;
  return node;
}

void btree_insert(link *root, int key) {
  link *node = btree_create_node(key);
  queue q = {0, .size = 256};
  q.q[q.eq_idx++ % q.size] = root;
  while (q.dq_idx != q.eq_idx) {
    link *curr = q.q[q.dq_idx++ % q.size];
    if (curr->l == NULL) {
      curr->l = node;
      break;
    }
    q.q[q.eq_idx++ % q.size] = curr->l;

    if (curr->r == NULL) {
      curr->r = node;
      break;
    }
    q.q[q.eq_idx++ % q.size] = curr->r;
  }
}

int main(void) {
  link *node = btree_create_node(1);
  link *node1 = btree_create_node(2);
  // link *node2 = btree_create_node(3);
  // link *node3 = btree_create_node(4);
  // link *node4 = btree_create_node(5);
  // link *node5 = btree_create_node(6);
  node->l = node1;
  // node->r = node2;
  // node2->l = node3;
  // node2->r = node4;
  // node3->l = node5;

  // inorder_traverse(node);
  // post_traverse(node);
  btree_insert(node, 3);
  btree_insert(node, 4);
  btree_insert(node, 5);
  btree_insert(node, 6);
  btree_insert(node, 7);
  // level_traverse(node);
  pre_traverse(node);

  return 0;
}
