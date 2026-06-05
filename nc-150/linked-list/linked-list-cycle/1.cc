#include <unordered_map>

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
    std::unordered_map<void *, int> map;
    ListNode *cur = head;
    while (cur) {
      if (map.find(cur) != map.end()) {
        return true;
      }
      map[cur] = 1;
      cur = cur->next;
    }
    return false;
  }
};

int main(void) { return 0; }
