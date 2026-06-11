#include "../ll1.h"

// class Solution {
//   ListNode *add_numbers(ListNode *l1, ListNode *l2){
//     ListNode *s;
//   }
// };

int main(void) {
  ListNode *head = new ListNode(1);
  head = head->append(head, 2);
  head->print();
  return 0;
}
