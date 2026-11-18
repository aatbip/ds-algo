/*2487. Remove Nodes From Linked List-
 * You are given the head of a linked list.
 * Remove every node which has a node with a greater value anywhere to the right side of it.
 * Return the head of the modified linked list.
 *
 * Solution - Solved using monotonic stack.
 *
 * Time complexity- O(n), because each node is pushed exactly once and popped at most once. The total work in the inner
 * while loop is bounded by 'n' pops.
 *
 * Space complexity- O(n) for the stack
 * */

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
    ListNode *cur = head;
    while (cur) {
      while (!s.empty() && s.top()->val < cur->val) {
        delete s.top();
        s.pop();
      }
      s.push(cur);
      cur = cur->next;
    }
    ListNode *prev = nullptr;
    while (!s.empty()) {
      s.top()->next = prev;
      prev = s.top();
      s.pop();
    }
    return prev;
  }
};

int main(void) {
  Solution s;

  ListNode *root = new ListNode(5);
  ListNode *t = root;
  std::vector<int> v = {2, 13, 3, 8};
  for (int i = 0; i < v.size(); i++) {
    ListNode *n = new ListNode(v[i]);
    t->next = n;
    t = n;
  }

  root = s.remove_nodes(root);
  ListNode *cur = root;
  while (cur) {
    std::cout << cur->val << "\n";
    cur = cur->next;
  }

  return 0;
}
