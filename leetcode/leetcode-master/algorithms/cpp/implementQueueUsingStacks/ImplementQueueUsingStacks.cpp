// Source : https://leetcode.com/problems/implement-queue-using-stacks/
// Author : Hao Chen
// Date   : 2015-07-16

/********************************************************************************** 
 * 
 * Implement the following operations of a queue using stacks.
 * 
 * push(x) -- Push element x to the back of queue.
 * 
 * pop() -- Removes the element from in front of queue.
 * 
 * peek() -- Get the front element.
 * 
 * empty() -- Return whether the queue is empty.
 * 
 * Notes:
 * 
 * You must use only standard operations of a stack -- which means only push to top, 
 * peek/pop from top, size, and is empty operations are valid.

 * Depending on your language, stack may not be supported natively. You may simulate a 
 * stack by using a list or deque (double-ended queue), as long as you use only 
 * standard operations of a stack.

 * You may assume that all operations are valid (for example, no pop or peek operations 
 * will be called on an empty queue).
 *               
 **********************************************************************************/

class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        s1.push(x);
    }

    // Removes the element from in front of queue.
    // next way: return int, it is the top, such as implement below
    void pop(void) {
        transfer(s1, s2);
        s2.pop();
        transfer(s2, s1);
    }

    // Get the front element.
    int peek(void) {
        transfer(s1, s2);
        int ret = s2.top();
        transfer(s2, s1);
        return ret;
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return s1.empty();
    }
private:
    stack<int> s1, s2;
    void transfer(stack<int>& s1, stack<int>& s2) {
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
    }
};


// my code 2017/10/16
class MyQueue {
public:
  /** Initialize your data structure here. */
  MyQueue()
  {

  }
  
  /** Push element x to the back of queue. */
  void push(int x)
  {
    s1.push(x);
  }
  
  /** Removes the element from in front of queue and returns that element. */
  int pop()
  {
    transfer(s1, s2);
    int top = s2.top();
    s2.pop();
    transfer(s2, s1);
    return top;
  }
  
  /** Get the front element. */
  int peek()
  {
    transfer(s1, s2);
    int peek = s2.top();
    transfer(s2, s1);
    return peek;
  }
  
  /** Returns whether the queue is empty. */
  bool empty()
  {
    return s1.empty();
  }

private:
  std::stack<int> s1; // input to the stack, if the queue isn't empty, the stack isn't empty
  std::stack<int> s2; // output from the stack, after the operation, the stack is empty,

  void transfer(std::stack<int>& from, std::stack<int>& to)
  {
    while (from.size())
    {
      to.push(from.top());
      from.pop();
    }
  }
};