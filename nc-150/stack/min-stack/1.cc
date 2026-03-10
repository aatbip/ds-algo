/*Design a stack class that supports the push, pop, top, and getMin operations.
 * - MinStack() initializes the stack object.
 * - void push(int val) pushes the element val onto the stack.
 * - void pop() removes the element on the top of the stack.
 * - int top() gets the top element of the stack.
 * - int getMin() retrieves the minimum element in the stack.
 * Each function should run in O(1) time.
 * */

#include <iostream>
#include <stack>

class MinStack {
private:
  std::stack<int> stack;
  long min;

public:
  MinStack() {}

  void push(int val) {
    if (stack.empty()) {
      stack.push(0);
      min = val;
    } else {
      stack.push(min - val);
      if (val < min)
        min = val;
    }
  }

  int top(void) {
    if (stack.top() < 0) {
      return min - stack.top();
    } else {
      return min;
    }
  }

  void pop(void) {
    if (stack.top() < 0) {
      stack.pop();
    } else {
      min = stack.top() + min;
      stack.pop();
    }
  }
};

int main(void) {
  MinStack ms;
  ms.push(5);
  ms.push(2);
  ms.pop();
  ms.pop();
  std::cout << ms.top() << "\n";
  return 0;
}
