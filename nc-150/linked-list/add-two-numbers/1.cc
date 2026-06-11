#include "../ll1.h"

// class Solution {
//   ListNode *add_numbers(ListNode *l1, ListNode *l2){
//     ListNode *s;
//   }
// };

int main(void) {
  ListNode *l1 = new ListNode(9);
  l1->append(1);

  ListNode *l2 = new ListNode(9);
  l2->append(9);

  l1->print();
  l2->print();

  return 0;
}
