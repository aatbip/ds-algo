#include <iostream>
#include <unordered_set>

class ListNode {
public:
  int val;
  ListNode *next;

  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  bool hasCycle(ListNode *head) {
    std::unordered_set<ListNode *> set;
    ListNode *cur = head;
    while (cur) {
      if (set.find(cur) != set.end()) {
        return true;
      }
      set.insert(cur);
      cur = cur->next;
    }
    return false;
  }
};

int main(void) {
  ListNode *head = new ListNode(0);
  head = new ListNode(1, head);
  ListNode *temp = head = new ListNode(2, head);
  head = new ListNode(3, head);

  // create a cycle
  ListNode *cur = head;
  while (cur) {
    if (cur->next == nullptr) {
      cur->next = temp;
      break;
    }
    cur = cur->next;
  }

  Solution s;
  std::cout << s.hasCycle(head) << "\n";
  return 0;
}
