#ifndef LL1_H
#define LL1_H

#include <cstring>
#include <iostream>
#include <vector>

/*Not at all optimized linked list just for testing my solutions. For ex `append` method is O(n) which can be made to be
 * O(1) using a state to track the tail node.*/
class ListNode {
public:
  int val;
  ListNode *next;
  ListNode *random;

  ListNode() : val(0), next(nullptr), random(nullptr) {}
  ListNode(int x) : val(x), next(nullptr), random(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next), random(nullptr) {}

  static ListNode *make(std::vector<int> &arr) {
    ListNode *head = nullptr;
    for (int i = arr.size() - 1; i >= 0; --i) {
      head = new ListNode(arr[i], head);
    }
    return head;
  }

  ListNode *append(int x) {
    ListNode *cur = this;
    while (cur->next)
      cur = cur->next;
    cur->next = new ListNode(x);
    return this;
  }

  void print() {
    ListNode *cur = this;
    while (cur) {
      std::cout << cur->val << "\n";
      cur = cur->next;
    }
  }
};

#endif
