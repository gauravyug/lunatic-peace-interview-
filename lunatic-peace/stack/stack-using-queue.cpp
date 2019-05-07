
// C++ program to implement a stack using
// single queue
#include<bits/stdc++.h>
using namespace std;
 
// User defined stack that uses a queue
class Stack
{
    queue<int>q;
public:
    void push(int val);
    void pop();
    int top();
    bool empty();
};
 
// Push operation
void Stack::push(int val)
{
    //  Get previous size of queue
    int s = q.size();
 
    // Push current element
    q.push(val);
 
    // Pop (or Dequeue) all previous
    // elements and put them after current
    // element
    for (int i=0; i<s; i++)
    {
        // this will add front element into
        // rear of queue
        q.push(q.front());
 
        // this will delete front element
        q.pop();
    }
}
 
// Removes the top element
void Stack::pop()
{
    if (q.empty())
        cout << "No elements\n";
    else
        q.pop();
}
 
// Returns top of stack
int  Stack::top()
{
    return (q.empty())? -1 : q.front();
}
 
// Returns true if Stack is empty else false
bool Stack::empty()
{
    return (q.empty());
}
 
// Driver code
int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    cout << s.top() << endl;
    s.pop();
    s.push(30);
    s.pop();
    cout << s.top() << endl;
    return 0;
}
class MyStack {
public:
    queue<int> q1, q2; 
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
         q1.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if (q1.empty() && q2.empty()) {
            return -1;
        }
        else {
            while (q1.size() > 1) {
                q2.push(q1.front());
                q1.pop();
            }

            int top = q1.front(); 
            q1.pop(); 
            queue<int> temp = q1;
            q1= q2;
            q2 = temp;
            return top;
        }
    }
    
    /** Get the top element. */
    int top() {
        if (q1.empty()) 
            return -1; 
  
        while( q1.size() != 1 ) 
        { 
           q2.push(q1.front()); 
           q1.pop(); 
        }  
        int top = q1.front(); 
          
        q1.pop(); 
       
        q2.push(top); 
  
        queue<int> q = q1; 
        q1 = q2; 
        q2 = q; 
        return top; 
        
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty() && q2.empty();
    }
};


/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */