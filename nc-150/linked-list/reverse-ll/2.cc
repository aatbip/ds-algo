#include <iostream>

class ListNode {
  int val;
  ListNode *next;

public:
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}

  ListNode *reverse_ll() {
    ListNode *prev = NULL;
    ListNode *cur = this;
    while (cur) {
      ListNode *temp = cur->next;
      cur->next = prev;
      prev = cur;
      cur = temp;
    }
    return prev;
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
  int arr[] = {1, 2, 3, 4, 5};
  for (int i = 0; i < 5; i++) {
    head = new ListNode(arr[i], head);
  }

  head->print();
  ListNode *rh = head->reverse_ll();
  std::cout << "reversed: \n";
  rh->print();
}
