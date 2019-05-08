// CPP program to implement Queue using 
// two stacks with costly deQueue() 
#include <bits/stdc++.h> 
using namespace std; 

class MyQueue {
public:
    /** Initialize your data structure here. */
    stack <int> s1;
    stack <int> s2;
    
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
            s1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int top = -1;
        if (s1.empty() && s2.empty())
            return top;
        else {
           if (s2.empty()) { 
                while (!s1.empty()) { 
                    s2.push(s1.top()); 
                    s1.pop(); 
                } 
            } 
            top = s2.top(); 
            s2.pop(); 
            return top; 
        }  
    }
        
    
    /** Get the front element. */
    int peek() {
         while(s2.empty()) {
            while(!s1.empty()) {
                int x = s1.top();
                s1.pop();
                s2.push(x);
            }
        }
        int x = s2.top();
        // sta2.pop();
        return x;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
         return s1.empty() && s2.empty();
        
    }
};

// Driver code 
int main() 
{ 
	MyQueue q; 
	q.push(1); 
	q.push(2); 
	cout << q.peek() << '\n'; 
	cout << q.pop() << '\n';
	cout << q.empty() << '\n';
	q.push(3); 

	 
	cout << q.pop() << '\n'; 
	

	return 0; 
} 
