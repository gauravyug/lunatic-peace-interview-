#include <iostream>
#include <stack>
#include <queue>

using namespace std;


class Stack
{

        queue <int> q1, q2;
        int size;
        public:
        Stack(){
                size = 0;
        }

        void push(int data) {       
        cout << "Push item:" << data << "\n";
                q1.push(data);
        }

        int pop(){
                int item = 0xFF;
                while (!q1.empty() ) {
                        if (q1.size() == 1) {
                                item = q1.front();
                                q1.pop();
                                goto out;
                        }
                q2.push(q1.front());
                q1.pop();
                }       
out:            
                queue <int >temp = q1;
                q1 = q2;
                q2 = temp;
                return item;
        }
};


class Queue
{

        stack <int> s1, s2;
        int size;
        public:
        Queue(){
                size = 0;
        }

        void enqueue(int data) {
        cout << "Enqueue item:" << data << "\n";
                s1.push(data);
        }

        int dequeue(){
                int item = 0xFF;
                while (!s1.empty() ) {
                        if (s1.size() == 1) {
                                item = s1.top();
                                s1.pop();
                                goto out;
                        }
                s2.push(s1.top());
                s1.pop();
                }
out:
                stack <int >temp = s1;
                s1 = s2;
                s2 = temp;
                return item;
        }
};
/*void push (int data)
{
        cout << "Push item:" << data;
        q1.push(data);
        cout << "\n";
}

int pop()
{
        queue <int> temp;
        int item = 0xFF;
        while (!q1.empty() ) {
                if (q1.size() == 1) {
                        item = q1.front();
                        q1.pop();
                        goto out;
                }
            q2.push(q1.front());
            q1.pop();
        }
out:
        temp = q1;
        q1 = q2;
        q2 = temp;
        return item;
}
*/
int main()
{
        Stack s;
        s.push(5);
        s.push(3);
        s.push(1);
        s.push(6);

        cout <<"Popped Item is:" << s.pop() <<" \n";
        cout <<"Popped Item is:" << s.pop() <<" \n";
        s.push(16);
        s.push(68);

        cout <<"Popped Item is:" << s.pop() <<" \n";

        Queue q;
        q.enqueue(5);
        q.enqueue(15);
        q.enqueue(0);
        q.enqueue(78);

        cout <<"Dequeue Item is:" << q.dequeue() <<" \n";
        q.enqueue(10);
        q.enqueue(8);
        cout <<"Dequeue Item is:" << q.dequeue() <<" \n";
        cout <<"Dequeue Item is:" << q.dequeue() <<" \n";
        return 0;
}
