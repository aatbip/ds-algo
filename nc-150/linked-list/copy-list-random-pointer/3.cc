/*You are given the head of a linked list of length n. Unlike a singly linked list, each node contains an additional
 * pointer random, which may point to any node in the list, or null.
 * Create a deep copy of the list.
 *
 * The deep copy should consist of exactly n new nodes, each including:
 * -> The original value val of the copied node
 * -> A next pointer to the new node corresponding to the next pointer of the original node
 * -> A random pointer to the new node corresponding to the random pointer of the original node
 *
 * Note: None of the pointers in the new list should point to nodes in the original list.
 * Return the head of the copied linked list.
 * In the examples, the linked list is represented as a list of n nodes. Each node is represented as a pair of [val,
 * random_index] where random_index is the index of the node (0-indexed) that the random pointer points to, or null if
 * it does not point to any node.
 *
 * Solution:
 * This method optimizes for space by using O(1) extra space. The idea is to create a list in the first iteration that
 * looks like this: A -> A' -> B -> B' -> C -> C' -> ... and so on Where, A' is the exact copy of A.
 *
 * Then in the second iteration, we will handle the 'random' pointer of the copied nodes.
 * Then in the third iteration we will detatch the original nodes and only maintain the list of the copied nodes.
 *
 * Time complexity- O(n)
 * Space complexity- O(1) and O(n) for the copied list
 * */

#include "../ll1.h"

class Solution {
public:
  ListNode *deep_copy(ListNode *head) {
    if (head == nullptr) {
      return nullptr;
    }
    ListNode *cur = head;
    while (cur) {
      ListNode *copy = new ListNode(cur->val);
      copy->next = cur->next;
      cur->next = copy;
      cur = copy->next;
    }

    cur = head;
    while (cur) {
      if (cur->random) {
        cur->next->random = cur->random->next;
      }
      cur = cur->next->next;
    }

    cur = head;
    ListNode *copy_head = head->next;
    ListNode *cur_copy = copy_head;
    while (cur) {
      cur->next = cur->next->next;
      cur_copy->next = cur->next ? cur_copy->next->next : nullptr;
      cur = cur->next;
      cur_copy = cur_copy->next;
    }
    return copy_head;
  }
};
