#include<bits/stdc++.h>

using namespace std;

void insert(int item, stack<int> *s) {
    if (s->empty() || s->top() <= item) {
        s->push(item);
    }
    else {
        int top = s->top();
        s->pop();
        insert(item, s);
        s->push(top);
    }
}
void sortstackrecursive(stack<int> *s)
{
    if (!s->empty()) {
        int val = s->top();
        s->pop();
        sortstackrecursive(s);
        insert(val, s);
    }
}

void sortstackiterative(stack<int> *s) {
    stack <int> *r;
    while (!s->empty()) {
        int tmp = s->top();
        s->pop();
        while (!r->empty() && r->top() > tmp ) {
            int val = r->top();
            r->pop();
            s->push(val);
        }
        r->push(tmp);
    }
    while (!r->empty()) {
        int val = r->top();
        r->pop();
        s->push(val);
    }
}

stack<int> sortStack(stack<int> &input) 
{ 
    stack<int> tmpStack; 
  
    while (!input.empty()) 
    { 
        // pop out the first element 
        int tmp = input.top(); 
        input.pop(); 
  
        // while temporary stack is not empty and top 
        // of stack is greater than temp 
        while (!tmpStack.empty() && tmpStack.top() > tmp) 
        { 
            // pop from temporary stack and push 
            // it to the input stack 
            input.push(tmpStack.top()); 
            tmpStack.pop(); 
        } 
  
        // push temp in tempory of stack 
        tmpStack.push(tmp); 
    } 
  
    return tmpStack; 
} 

int main() {
    stack <int> s;
    s.push(15);
    s.push(7);
    s.push(5);
    s.push(12);
   // sortstackrecursive(&s);
    s = sortStack(s);
    while (!s.empty()) {
    int val = s.top();
    cout << val << endl;
        s.pop();
    }
    return 0;
}