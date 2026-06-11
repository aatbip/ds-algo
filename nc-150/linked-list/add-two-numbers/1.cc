#include "../ll1.h"

class Solution {
public:
  ListNode *add_numbers(ListNode *l1, ListNode *l2) {
    ListNode *s = nullptr;
    int carry = 0;
    ListNode *cur_l1 = l1;
    ListNode *cur_l2 = l2;
    while (cur_l1 && cur_l2) {
      int sum = cur_l1->val + cur_l2->val + carry;
      if (sum >= 10) {
        carry = sum / 10;
        s->append(sum - 10);
      } else {
        s->append(sum);
      }
      cur_l1 = l1->next;
      cur_l2 = l2->next;
    }
    return s;
  }
};

int main(void) {
  ListNode *l1 = nullptr;
  l1->append(1);
  l1->append(2);
  // ListNode *l1 = new ListNode(9);
  l1->append(1);

  // ListNode *l2 = new ListNode(9);
  // l2->append(9);
  //
  // l1->print();
  // l2->print();
  //
  // Solution s;
  // ListNode *sum = s.add_numbers(l1, l2);
  // sum->print();

  return 0;
}
