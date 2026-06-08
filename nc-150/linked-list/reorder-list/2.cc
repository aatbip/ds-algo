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
 * This program uses slow and fast pointer approach to divide the linked list from the middle node. Then, the list from
 * middle node to the tail is reversed and then two pointer approach is used to reorder the list.
 *
 * Time complexity- O(n)
 * Space complexity- O(1), because no extra space is used
 * */

#include "../ll1.h"
#include <cstring>
#include <vector>

class Solution {
public:
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
    while (l) {
      ListNode *ltemp = l->next;
      ListNode *rtemp = r->next;
      l->next = r;
      r->next = ltemp;
      l = ltemp;
      r = rtemp;
    }
  }
};

int main(void) {
  std::vector<int> arr = {2, 4, 6, 8};
  ListNode *head = ListNode::make(arr);

  Solution s;
  s.reorder_list(head);
  head->print();

  return 0;
}
