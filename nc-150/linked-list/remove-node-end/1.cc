#include "../ll1.h"
#include <iostream>
#include <vector>

class Solution {
public:
  ListNode *remove_nth_node(ListNode *head, int n) {
    ListNode *cur = head;
    ListNode *prev = head;
    int i = 0;
    int size = 0;
    while (cur) {
      cur = cur->next;
      size++;
    }
    cur = head;
    while (cur) {
      if (i == size - n) {
        if (i == 0) {
          return cur->next;
        }
        prev->next = cur->next;
        break;
      }
      prev = cur;
      cur = cur->next;
      i++;
    }
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
