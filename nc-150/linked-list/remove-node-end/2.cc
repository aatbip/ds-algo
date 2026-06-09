#include "../ll1.h"
#include <iostream>
#include <vector>

class Solution {
public:
  ListNode *remove_nth_node(ListNode *head, int n) {
    ListNode *fast = head;
    ListNode *slow = head;
    ListNode *cur = head;
    for (int i = 1; i < n; i++) {
      fast = fast->next;
    }
    int c = 0;
    ListNode *prev = head;
    while (fast) {
      fast = fast->next;
      if (fast) {
        prev = slow;
        slow = slow->next;
        c++;
      }
    }
    if (c == 0)
      return prev->next;
    prev->next = slow->next;
    return head;
  }
};

int main(void) {
  std::vector<int> arr = {1, 2};
  ListNode *head = ListNode::make(arr);
  head->print();
  std::cout << "\n";

  Solution s;
  head = s.remove_nth_node(head, 1);
  head->print();

  return 0;
}
