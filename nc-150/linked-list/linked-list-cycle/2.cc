/* Given the beginning of a linked list head, return true if there is a cycle in the linked list. Otherwise, return
 * false. There is a cycle in a linked list if at least one node in the list can be visited again by following the next
 * pointer. Internally, index determines the index of the beginning of the cycle, if it exists. The tail node of the
 * list will set it's next pointer to the index-th node. If index = -1, then the tail node points to null and no cycle
 * exists.
 *
 * Note: index is not given to you as a parameter.
 *
 * This program solves the problem using fast and slow pointer technique.
 *
 * Time complexity- O(n)
 * Space complexity- O(1)
 *
 * */

#include <iostream>
#include <unordered_set>

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
  bool hasCycle(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast) {
        return true;
      }
    }
    return false;
  }
};

int main(void) {
  ListNode *head = new ListNode(0);
  head = new ListNode(1, head);
  ListNode *temp = head = new ListNode(2, head);
  head = new ListNode(3, head);

  ListNode *cur = head;
  // create a cycle
  while (cur) {
    if (cur->next == nullptr) {
      cur->next = temp;
      break;
    }
    cur = cur->next;
  }

  Solution s;
  std::cout << s.hasCycle(head) << "\n";
  return 0;
}
