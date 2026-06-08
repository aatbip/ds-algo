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
