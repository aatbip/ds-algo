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
      map[cur]->next = cur->next;
      map[cur]->random = cur->random;
      cur = cur->next;
    }
    return map[head];
  }
};
