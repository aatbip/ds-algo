/*You are given the head of a singly linked list head and a positive integer k. You must reverse the first k nodes
 * in the linked list, and then reverse the next k nodes, and so on. If there are fewer than k nodes left, leave the
 * nodes as they are. Return the modified list after reversing the nodes in each group of k. You are only allowed to
 * modify the nodes' next pointers, not the values of the nodes.
 *
 * Solution-
 * Solved iteratively.
 * Time complexity: O(n)
 * Space complexity: O(1)
 * */

#include "../ll1.h"

#include <cstdio>
#include <iostream>
#include <vector>

class Solution {
  ListNode *get_kth(ListNode *node, int k) {
    ListNode *cur = node;
    while (cur && k > 0) {
      cur = cur->next;
      k--;
    }
    return cur;
  }

public:
  ListNode *reverse_nodes(ListNode *head, int k) {
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *group_prev = dummy;
    while (true) {
      ListNode *kth = get_kth(group_prev, k);
      if (!kth) {
        break;
      }
      ListNode *prev = kth->next;
      ListNode *cur = group_prev->next;
      ListNode *stop = kth->next;
      while (cur != stop) {
        ListNode *temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
      }
      ListNode *tmp = group_prev->next;
      std::cout << "gp: " << group_prev->next->val << "\n";
      group_prev->next = kth;
      group_prev = tmp;
    }
    return dummy->next;
  }
};

int main(void) {
  std::vector<int> arr = {1, 2, 3, 4, 5, 6};
  ListNode *head = ListNode::make(arr);

  Solution s;
  ListNode *r = s.reverse_nodes(head, 3);
  r->print();

  return 0;
}
