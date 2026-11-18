// Remove nodes from linked list

#include <iostream>
#include <stack>
#include <vector>
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
  ListNode *remove_nodes(ListNode *head) {
    std::stack<ListNode *> s;
    s.push(head);
    ListNode *cur = head->next;
    while (cur) {
      while (!s.empty() && s.top()->val < cur->val) {
        s.pop();
      }
      s.push(cur);
      cur = cur->next;
    }
    head = new ListNode(s.top()->val);
    while (!s.empty()) {
      s.pop();
      if (!s.empty()) {
        ListNode *n = new ListNode(s.top()->val, head);
        head = n;
      }
    }
    return head;
  }
};

int main(void) {
  Solution s;

  ListNode *root = new ListNode(1);
  ListNode *t = root;
  std::vector<int> v = {1, 1, 1};
  for (int i = 0; i < v.size(); i++) {
    ListNode *n = new ListNode(v[i]);
    t->next = n;
    t = n;
  }

  s.remove_nodes(root);

  return 0;
}
