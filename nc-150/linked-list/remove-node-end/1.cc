#include "../ll1.h"
#include <vector>

int main(void) {
  std::vector<int> arr = {1, 2, 3, 4};
  ListNode *head = ListNode::make(arr);
  head->print();

  return 0;
}
