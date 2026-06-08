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
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }
    // here slow points at midpoint
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
  std::vector<int> arr = {2, 4, 6, 8};
  for (int i = arr.size() - 1; i >= 0; --i) {
    head = new ListNode(arr[i], head);
  }
  head->print();
  std::cout << "\n";

  head->reorder_list(head);

  return 0;
}
