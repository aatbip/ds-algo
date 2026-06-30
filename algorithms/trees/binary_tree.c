#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Item {
  int key;
} Item;

typedef struct node {
  Item item;
  struct node *l;
  struct node *r;
} link;

#define QUEUE_SIZE 256
typedef struct {
  link *queue[QUEUE_SIZE];
  int dq_idx;
  int eq_idx;
} queue;

void enque(queue *q, link *node) {
  q->queue[q->eq_idx] = node;
  q->eq_idx = (q->eq_idx + 1) % QUEUE_SIZE;
}

link *deque(queue *q) {
  link *node = q->queue[q->dq_idx];
  q->dq_idx = (q->dq_idx + 1) % QUEUE_SIZE;
  return node;
}

// preorder traversal (DFS)
void pre_traverse(link *node) {
  if (!node)
    return;
  printf("%d\n", node->item.key);
  pre_traverse(node->l);
  pre_traverse(node->r);
}
// inorder traversal (DFS)
void inorder_traverse(link *node) {
  if (!node)
    return;
  inorder_traverse(node->l);
  printf("%d\n", node->item.key);
  inorder_traverse(node->r);
}
// postorder traversal (DFS)
void post_traverse(link *node) {
  if (!node)
    return;
  post_traverse(node->l);
  post_traverse(node->r);
  printf("%d\n", node->item.key);
}

// level traversal (BFS)
void level_traverse(link *node) {
  queue q;
  memset(&q, 0, sizeof(queue));
  enque(&q, node);
  while (q.dq_idx != q.eq_idx) {
    link *curr = deque(&q);
    printf("%d\n", curr->item.key);
    if (curr->l)
      enque(&q, curr->l);
    if (curr->r)
      enque(&q, curr->r);
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
  queue q;
  memset(&q, 0, sizeof(queue));
  enque(&q, root);
  while (1) {
    link *curr = deque(&q);
    if (curr->l == NULL) {
      curr->l = node;
      break;
    }
    enque(&q, curr->l);
    if (curr->r == NULL) {
      curr->r = node;
      break;
    }
    enque(&q, curr->r);
  }
}

void btree_free(link *root) {
  if (!root)
    return;
  btree_free(root->l);
  btree_free(root->r);
  free(root);
}

int count(link *h) {
  if (h == NULL)
    return 0;
  return count(h->l) + count(h->r) + 1;
}

int height(link *h) {
  int u, v;
  if (h == NULL)
    return -1;
  u = height(h->l);
  v = height(h->r);
  if (u > v)
    return u + 1;
  return v + 1;
}

int main(void) {
  link *root = btree_create_node(10);
  link *node1 = btree_create_node(8);
  root->l = node1;
  btree_insert(root, 15);
  btree_insert(root, 7);
  btree_insert(root, 9);
  btree_insert(root, 12);
  btree_insert(root, 25);

  // level_traverse(root);
  // btree_insert(root, 8);
  // level_traverse(root);
  inorder_traverse(root);
  // post_traverse(root);
  // pre_traverse(root);

  // printf("height: %d\n", height(root));
  // printf("count: %d\n", count(root));

  btree_free(root);

  return 0;
}
