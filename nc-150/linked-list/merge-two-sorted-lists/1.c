#include "../ll.h"
#include <stdio.h>
#include <stdlib.h>

ll *merge_list(ll *list1, ll *list2) {
  ll *prev = list1;
  ll *next = list2;
  ll *pprev = NULL;
  if (!prev) {
    return next;
  } else if (!next) {
    return prev;
  }
  while (next) {
    if (next->key > prev->key || next->key == prev->key) {
      ll *temp = prev->next;
      pprev = prev;
      prev->next = next;
      prev = next;
      next = temp;
    } else {
      ll *temp = next->next;
      next->next = prev;
      if (pprev)
        pprev->next = next;
      next = temp;
    }
  }
  if (list1->next)
    return list1;
  return list2;
}

int main(void) {
  ll *list1 = create_list(2);
  // insert_node(list1, 3);
  // insert_node(list1, 5);

  ll *list2 = create_list(1);
  // insert_node(list2, 2);
  // insert_node(list2, 4);

  printf("before merge: \n");
  download_ll(list1);
  download_ll(list2);

  printf("\nadter merge: \n");
  list1 = merge_list(list1, list2);
  download_ll(list1);

  return 0;
}
