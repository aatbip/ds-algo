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
    ListNode *fast = head->next;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }

    // Reverse the partial list to the right of middle where middle is pointer by 'slow'
    ListNode *prev = NULL;
    ListNode *cur = slow;
    while (cur) {
      ListNode *temp = cur->next;
      cur->next = prev;
      prev = cur;
      cur = temp;
    }

    ListNode *l = head;
    ListNode *r = prev;
    while (r) {
      ListNode *ltemp = l->next;
      ListNode *rtemp = r->next;
      l->next = r;
      r->next = rtemp ? ltemp : rtemp;
      l = ltemp;
      r = rtemp;
    }
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
  head->print();

  return 0;
}
