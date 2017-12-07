#include <iostream>

using namespace std;

class Stack {
        private:
                int *arr;
                int top;
                int capacity;
        public:
                Stack(int size);
                void push(int item);
                int pop();
                int peek();
                int size();

                bool isFull();
                bool isEmpty();
};
