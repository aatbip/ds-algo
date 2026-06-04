#include "../ll.h"
#include <stdio.h>
#include <stdlib.h>

ll *merge_list(ll *list1, ll *list2) {
  ll *prev = list1;
  ll *next = list2;
  while (next) {
    if (next->key > prev->key) {
      ll *temp = prev->next;
    }
  }
}

int main(void) {
  ll *list1 = create_list(1);
  insert_node(list1, 3);
  insert_node(list1, 5);

  ll *list2 = create_list(1);
  insert_node(list1, 2);
  insert_node(list1, 4);

  download_ll(list1);
  download_ll(list2);

  return 0;
}
