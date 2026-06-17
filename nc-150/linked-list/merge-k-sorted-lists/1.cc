/*You are given an array of k linked lists lists, where each list is sorted in ascending order.
 * Return the sorted linked list that is the result of merging all of the individual linked lists.
 *
 * Solution-
 * This program solves using the `merge_two_list` method to merge combination of linked list in the lists two at a time.
 *
 * Time complexity- O(n * k), where 'n' is the number of nodes in the largest linked list and 'k' is the size of list.
 * Space complexity- O(k), because 'k' number of dummy nodes were created in `merge_two_lists`.
 *
 * Not a scalable solution.
 * */

#include "../ll1.h"
#include <vector>

class Solution {
  ListNode *merge_two_list(ListNode *l1, ListNode *l2) {
    ListNode *cur1 = l1;
    ListNode *cur2 = l2;
    ListNode *dummy = new ListNode(0);
    ListNode *tail = dummy;
    while (cur1 && cur2) {
      if (cur1->val <= cur2->val) {
        tail->next = cur1;
        cur1 = cur1->next;
      } else {
        tail->next = cur2;
        cur2 = cur2->next;
      }
      tail = tail->next;
    }
    tail->next = cur1 ? cur1 : cur2;
    return dummy->next;
  }

public:
  ListNode *mergeKLists(std::vector<ListNode *> &lists) {
    ListNode *m = NULL;
    for (int i = 0; i < lists.size(); i++) {
      m = merge_two_list(lists[i], m);
    }
    return m;
  }
};

int main(void) {
  std::vector a = {1, 2, 5, 10, 12, 44};
  std::vector b = {2, 4, 8};
  std::vector c = {10, 19, 21};
  ListNode *l1 = ListNode::make(a);
  ListNode *l2 = ListNode::make(b);
  ListNode *l3 = ListNode::make(c);

  std::vector<ListNode *> list = {l1, l2, l3};

  Solution s;
  ListNode *m = s.mergeKLists(list);
  m->print();

  return 0;
}
