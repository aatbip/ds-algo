/*You are given the heads of two sorted linked lists list1 and list2. Merge the two lists into one sorted linked list
 * and return the head of the new sorted linked list. The new list should be made up of nodes from list1 and list2.
 *
 * Input: list1 = [1,2,4], list2 = [1,3,5]
 * Output: [1,1,2,3,4,5]
 *
 * Solved using a dummy struct to save the pointer to head.
 * Time complexity- O(m + n), where 'm' is size of list1 and 'n' is size of list2
 * Space complexity- O(1)
 * */

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
