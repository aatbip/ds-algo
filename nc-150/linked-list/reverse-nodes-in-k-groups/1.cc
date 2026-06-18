#include "../ll1.h"

#include <queue>
#include <vector>

class Solution {
public:
  ListNode *reverse_nodes(ListNode *head, int k) {
    ListNode *last_tail = nullptr;
    int i = 0;
    int scale = 1;
    ListNode *prev = nullptr;
    ListNode *cur = head;
    ListNode *new_head = nullptr;
    std::queue<ListNode *> q;
    while (cur) {
      if (i - k == 0) {
        if (scale == 1) {
          new_head = prev;
        }
        k = k * (scale + 1);
        scale++;
        q.push(head);
        head = cur;
        prev = nullptr;
      }
      ListNode *temp = cur->next;
      cur->next = prev;
      prev = cur;
      cur = temp;
      i++;
    }
    q.push(prev);
    while (!q.empty()) {
      ListNode *temp = q.front();
      q.pop();
      ListNode *next = q.front();
      temp->next = next;
      q.pop();
    }

    return new_head;
  }
};

int main(void) {
  std::vector<int> arr = {1, 2, 3, 4, 5};
  ListNode *head = ListNode::make(arr);

  Solution s;
  ListNode *r = s.reverse_nodes(head, 4);
  r->print();

  return 0;
}
