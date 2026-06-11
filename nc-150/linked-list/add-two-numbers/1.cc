#include "../ll1.h"

class Solution {
public:
  ListNode *add_numbers(ListNode *l1, ListNode *l2) {
    ListNode *dummy = new ListNode(0);
    ListNode *tail = dummy;
    int carry = 0;
    ListNode *cur_l1 = l1;
    ListNode *cur_l2 = l2;
    while (cur_l1 || cur_l2 || carry) {
      int sum = (cur_l1 ? cur_l1->val : 0) + (cur_l2 ? cur_l2->val : 0) + carry;
      carry = sum / 10;
      tail->next = new ListNode(sum % 10);
      tail = tail->next;
      cur_l1 = cur_l1 ? cur_l1->next : nullptr;
      cur_l2 = cur_l2 ? cur_l2->next : nullptr;
    }
    return dummy->next;
  }
};

int main(void) {
  ListNode *l1 = new ListNode(9);
  l1 = ListNode::append(l1, 9);
  l1 = ListNode::append(l1, 1);

  ListNode *l2 = new ListNode(9);
  l2 = ListNode::append(l2, 9);

  Solution s;
  ListNode *sum = s.add_numbers(l1, l2);
  sum->print();

  return 0;
}
