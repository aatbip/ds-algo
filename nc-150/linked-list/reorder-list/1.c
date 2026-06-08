#include "../ll.h"
#include <stdio.h>

void reorder_list(ll *head) {
  ll *cur = head;
  while (cur->next) {
    cur = cur->next;
  }
}

int main(void) {
  ll *head = create_list(2);
  insert_node(head, 4);
  insert_node(head, 6);
  insert_node(head, 8);
  download_ll(head);

  reorder_list(head);

  return 0;
}
