/* Given the head of a linked list and an integer n, remove the nth node from the end of the list and return its head.
 * Example-
 * Input: head = [1,2,3,4], n = 2
 * Output: [1,2,4]
 *
 * Solution:
 * This program uses slow and fast pointer approach.
 * Time complexity- O(n)
 * Space complexity- O(1)
 * */

#include "../ll1.h"
#include <iostream>
#include <vector>

class Solution {
public:
  ListNode *remove_nth_node(ListNode *head, int n) {
    ListNode *dummy = new ListNode(0, head);
    ListNode *slow = dummy;
    ListNode *fast = head;
    for (int i = 0; i < n; i++) {
      fast = fast->next;
    }
    while (fast) {
      fast = fast->next;
      slow = slow->next;
    }
    slow->next = slow->next->next;
    return dummy->next;
  }
};

int main(void) {
  std::vector<int> arr = {1, 2, 3, 4, 5};
  ListNode *head = ListNode::make(arr);
  head->print();
  std::cout << "\n";

  Solution s;
  head = s.remove_nth_node(head, 1);
  head->print();

  return 0;
}
