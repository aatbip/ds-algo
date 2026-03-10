/*Design a stack class that supports the push, pop, top, and getMin operations.
 * - MinStack() initializes the stack object.
 * - void push(int val) pushes the element val onto the stack.
 * - void pop() removes the element on the top of the stack.
 * - int top() gets the top element of the stack.
 * - int getMin() retrieves the minimum element in the stack.
 * Each function should run in O(1) time.
 *
 * The MinStack class is created using the std library's stack and `min` variable to track the minimum values.
 *
 * Time complexity - O(1) for all the operations
 * Space complexity - O(n)
 * */

#include <iostream>
#include <stack>

class MinStack {
private:
  std::stack<long> stack;
  long min;

public:
  MinStack() {}
  ~MinStack() {}

  void push(int val) {
    if (stack.empty()) {
      stack.push(0);
      min = val;
    } else {
      stack.push(val - min);
      if (val < min)
        min = val;
    }
  }

  int top(void) {
    long top = stack.top();
    return (top > 0) ? (top + min) : (int)min;
  }

  void pop(void) {
    if (stack.empty())
      return;

    long pop = stack.top();
    stack.pop();

    if (pop < 0)
      min = min - pop;
  }

  int get_min(void) { return (int)min; }
};

int main(void) {
  MinStack *ms = new MinStack();
  ms->push(5);
  ms->push(2);
  ms->pop();
  std::cout << ms->top() << "\n";
  return 0;
}
