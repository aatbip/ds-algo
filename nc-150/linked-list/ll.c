#include "ll.h"
#include <stdio.h>
#include <stdlib.h>

ll *create_list(int key) {
  ll *list = malloc(sizeof(ll));
  list->next = NULL;
  list->key = key;
  return list;
}

// not at all optimized way just for testing
void insert_node(ll *list, int key) {
  ll *node = malloc(sizeof(ll));
  node->key = key;
  node->next = NULL;
  ll *cur = list;
  while (cur->next) {
    cur = cur->next;
  }
  cur->next = node;
}

void download_ll(ll *list) {
  for (ll *p = list; p; p = p->next) {
    printf("key: %d\n", p->key);
  }
}
