#include "../ll.h"
#include <stdio.h>
#include <stdlib.h>

ll *merge_list(ll *list1, ll *list2) {
  ll *p1 = list1;
  ll *p2 = list2;
  ll dummy;
  ll *tail = &dummy;
  tail->next = NULL;
  while (p1 && p2) {
    if (p1->key <= p2->key) {
      tail->next = p1;
      p1 = p1->next;
    } else {
      tail->next = p2;
      p2 = p2->next;
    }
    tail = tail->next;
  }
  tail->next = p1 ? p1 : p2;
  return dummy.next;
}

int main(void) {
  ll *list1 = create_list(1);
  insert_node(list1, 3);
  insert_node(list1, 5);

  ll *list2 = create_list(1);
  insert_node(list2, 2);
  insert_node(list2, 4);

  printf("before merge: \n");
  download_ll(list1);
  download_ll(list2);

  printf("\nafter merge: \n");
  list1 = merge_list(list1, list2);
  download_ll(list1);

  return 0;
}
