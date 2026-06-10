#ifndef LL1_H
#define LL1_H

#include <cstring>
#include <iostream>
#include <vector>

class ListNode {
public:
  int val;
  ListNode *next;
  ListNode *random;

  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr), random(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}

  static ListNode *make(std::vector<int> &arr) {
    ListNode *head = nullptr;
    for (int i = arr.size() - 1; i >= 0; --i) {
      head = new ListNode(arr[i], head);
    }
    return head;
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
