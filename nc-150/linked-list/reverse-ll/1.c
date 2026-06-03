/*Given the beginning of a singly linked list head, reverse the list, and return the new beginning of the list.
 *
 * Example 1-
 *        Input : head = [0,1,2,3]
 *        Output: [3,2,1,0]
 * Example 1-
 *        Input : head = []
 *        Output: []
 * */

#include <stdio.h>
#include <stdlib.h>

typedef struct ll {
  int key;
  struct ll *next;
} ll;

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

ll *reverse_ll(ll *head) {
  ll *next, *prev;
  int i = 0;
  ll *cur = head;
  while (cur) {
    if (i == 0) {
      next = cur->next;
      prev = cur;
      cur->next = NULL;
      cur = next;
      i++;
    } else {
      next = cur->next;
      cur->next = prev;
      prev = cur;
      cur = next;
      i++;
    }
  }
  return prev;
}

int main(void) {
  ll *list = create_list(0);
  insert_node(list, 1);
  insert_node(list, 2);
  insert_node(list, 3);
  insert_node(list, 4);
  download_ll(list);

  printf("reversed: \n");
  ll *rev_list = reverse_ll(list);
  download_ll(rev_list);

  return 0;
}
