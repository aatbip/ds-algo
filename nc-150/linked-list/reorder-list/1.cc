/*You are given the head of a singly linked-list.
 * The positions of a linked list of length = 7 for example, can intially be represented as:
 * [0, 1, 2, 3, 4, 5, 6]
 *
 * Reorder the nodes of the linked list to be in the following order:
 * [0, 6, 1, 5, 2, 4, 3]
 *
 * Notice that in the general case for a list of length = n the nodes are reordered to be in the following order:
 * [0, n-1, 1, n-2, 2, n-3, ...]
 *
 * You may not modify the values in the list's nodes, but instead you must reorder the nodes themselves.
 *
 * Solution:
 * This program uses two pointer method which adds a vector class to store the linked list's nodes.
 * Time complexity- O(n)
 * Space complexity- O(n), because of the vector
 * */

#include <cstring>
#include <iostream>
#include <vector>

class ListNode {
  int val;
  ListNode *next;

public:
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}

  void reorder_list(ListNode *head) {
    std::vector<ListNode *> nodes;
    ListNode *cur = head;
    while (cur) {
      nodes.push_back(cur);
      cur = cur->next;
    }
    int l = 0;
    int r = nodes.size() - 1;
    while (l < r) {
      nodes[l]->next = nodes[r];
      l++;
      if (l >= r)
        break;
      nodes[r]->next = nodes[l];
      r--;
    }
    nodes[l]->next = nullptr;
  }

  void print() {
    ListNode *cur = this;
    while (cur) {
      std::cout << cur->val << "\n";
      cur = cur->next;
    }
  }
};

int main(void) {
  ListNode *head = nullptr;
  std::vector<int> arr = {8, 6, 4, 2};
  for (int i = 0; i < arr.size(); i++) {
    head = new ListNode(arr[i], head);
  }
  head->print();
  std::cout << "\n";

  head->reorder_list(head);
  head->print();

  return 0;
}
