/*Design a stack class that supports the push, pop, top, and getMin operations.
 * - MinStack() initializes the stack object.
 * - void push(int val) pushes the element val onto the stack.
 * - void pop() removes the element on the top of the stack.
 * - int top() gets the top element of the stack.
 * - int getMin() retrieves the minimum element in the stack.
 * Each function should run in O(1) time.
 * */

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
};

int main(void) { return 0; }
