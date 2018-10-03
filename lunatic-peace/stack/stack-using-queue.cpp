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
