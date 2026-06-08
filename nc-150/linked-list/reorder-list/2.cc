#include "../ll1.h"
#include <cstring>
#include <vector>

class Solution {
public:
  void reorder_list(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head->next;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }

    // Reverse the partial list to the right of middle where middle is pointer by 'slow'
    ListNode *prev = NULL;
    ListNode *cur = slow;
    while (cur) {
      ListNode *temp = cur->next;
      cur->next = prev;
      prev = cur;
      cur = temp;
    }

    ListNode *l = head;
    ListNode *r = prev;
    while (l) {
      ListNode *ltemp = l->next;
      ListNode *rtemp = r->next;
      l->next = r;
      r->next = ltemp;
      l = ltemp;
      r = rtemp;
    }
  }
};

int main(void) {
  std::vector<int> arr = {2, 4, 6, 8};
  ListNode *head = ListNode::make(arr);

  Solution s;
  s.reorder_list(head);
  head->print();

  return 0;
}
