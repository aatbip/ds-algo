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
 * Hashmap is used but this solution takes two pass.
 *
 * Time complexity- O(n+n) = O(2n) which becomes O(n) asymptotically.
 * Space complexity- O(n)
 * */

#include "../ll1.h"
#include <unordered_map>

class Solution {
public:
  ListNode *deep_copy(ListNode *head) {
    ListNode *cur = head;
    std::unordered_map<ListNode *, ListNode *> map;
    while (cur) {
      ListNode *copy = new ListNode(cur->val);
      map[cur] = copy;
      cur = cur->next;
    }
    cur = head;
    while (cur) {
      map[cur]->next = map[cur->next];
      map[cur]->random = map[cur->random];
      cur = cur->next;
    }
    return map[head];
  }
};
