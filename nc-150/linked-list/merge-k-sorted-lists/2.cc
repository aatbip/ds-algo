/*You are given an array of k linked lists lists, where each list is sorted in ascending order.
 * Return the sorted linked list that is the result of merging all of the individual linked lists.
 *
 * Solution-
 *
 * */

#include "../ll1.h"

class Solution {

public:
  ListNode *mergeKLists(std::vector<ListNode *> &lists) {}
};

int main() {

  std::vector a = {1, 2, 5, 10, 12, 44};
  std::vector b = {2, 4, 8};
  std::vector c = {10, 19, 21};
  ListNode *l1 = ListNode::make(a);
  ListNode *l2 = ListNode::make(b);
  ListNode *l3 = ListNode::make(c);

  std::vector<ListNode *> list = {l1, l2, l3};

  Solution s;
  ListNode *m = s.mergeKLists(list);

  return 0;
}
