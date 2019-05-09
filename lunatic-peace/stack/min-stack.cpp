/* https://leetcode.com/problems/min-stack/
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
Example:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.
*/
class MinStackUsingTwoStacks {
    /*
        In this class we'll use two stack.
    */
   stack<int> s1;
   stack<int> s2;
public:
    /** initialize your data structure here. */
    MinStackUsingTwoStacks() {
        
    }
    /*
        1. While pushing we'll dirctly push to stack-1
        2. We will check if stack-2 is empty OR x < min till now
            A. we will push to stack-2 
    */
    void push(int x) {
	    s1.push(x);
	    if (s2.empty() || x <= getMin())  s2.push(x);	    
    }
    void pop() {
	    if (s1.top() == getMin())  
            s2.pop();
	    s1.pop();
    }
    /*
        Top will be in Stack-1
    */
    int top() {
	    return s1.top();
    }
    /*
        Min will always be in Stack-2's top
    */
    int getMin() {
	    return s2.top();
    }
};