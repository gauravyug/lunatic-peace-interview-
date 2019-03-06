#include <iostream>
using namespace std;
class Stacks {

    int *topOfStack;
    int *stackData;
    int *nextIndex;
	int totalStacks;
    int nextAvailable = 0;
	public:
    //constructor to create k stacks in an array of size n
    Stacks(int numStacks, int capacity);
 
    // To push an item in stack number 'sn' where sn is from 0 to k-1
    void push(int stack, int value);
 
    // To pop an from stack number 'sn' where sn is from 0 to k-1
    int pop(int stack); 
	void print(int numstack, int capacit);
    // To check whether stack number 'sn' is empty or not
   // bool isEmpty(int sn)  {  return (topOfStack[sn] == -1); }
};
void Stacks::print(int numstack, int capacity)
{
	for (int i = 0; i < numstack; i++ )
		cout << topOfStack[i] << "\t";
	cout << "\n";
	
	for (int i = 0; i < capacity; i++ )
		cout << stackData[i] << "\t";
	cout << "\n";
	
	for (int i = 0; i < capacity; i++ )
		cout << nextIndex[i] << "\t";
	
	cout << "\n";

}
Stacks::Stacks(int numStacks, int capacity) {
        topOfStack = new int[numStacks];
        for (int i = 0; i < numStacks; i++) {
            topOfStack[i] = -1;
        }
        stackData = new int[capacity];
        nextIndex = new int[capacity];
        for (int i = 0; i < capacity - 1; i++) {
            nextIndex[i] = i+1;
        }
		totalStacks = numStacks;
        nextIndex[capacity - 1] = -1;
}

void Stacks::push(int value, int stack) {

        if (nextAvailable < 0 || stack >= totalStacks) return;

        int currentIndex = nextAvailable;
        nextAvailable = nextIndex[currentIndex];
        stackData[currentIndex] = value;
        nextIndex[currentIndex] = topOfStack[stack];
        topOfStack[stack] = currentIndex;
}


int Stacks::pop(int stack) {

        int currentIndex = topOfStack[stack];
        int value = stackData[currentIndex]; 
        topOfStack[stack] = nextIndex[currentIndex];
        nextIndex[currentIndex] = nextAvailable;
        nextAvailable = currentIndex;
        return value;
}


int main()
{
	 // Let us create 3 stacks in an array of size 10
    int k = 3, n = 10;
    Stacks ks(k, n);
 
    // Let us put some items in stack number 2
   /* ks.push(15, 2);
    ks.push(45, 2);
 
    // Let us put some items in stack number 1
    ks.push(17, 1);
    ks.push(49, 1);
    ks.push(39, 1);
 
    // Let us put some items in stack number 0
    ks.push(11, 0);
    ks.push(9, 0);
    ks.push(7, 0);*/
	cout << "Pushing 5 to 0 stack \n";
	ks.push(5, 0);
	ks.print (3, 6);
	cout << "Pushing 6 to 0 stack \n";
	ks.push(6, 0);
	ks.print (3, 6);
	cout << "Pushing 7 to 1 stack \n";
	ks.push(7, 1);
	ks.print (3, 6);
	cout << "Popping  from 0 stack \n";
	ks.pop(0);
	ks.print (3, 6);
	cout << "Pushing 8 to 2 stack \n";
	ks.push(8, 2);
	ks.print (3, 6);
    cout << "Popped element from stack 2 is " << ks.pop(2) << endl;
    cout << "Popped  from stack 1 is " << ks.pop(1) << endl;
    cout << "Popped element from stack 0 is " << ks.pop(0) << endl;
	cout << "Popped element from stack 2 is " << ks.pop(2) << endl;
    cout << "Popped element from stack 1 is " << ks.pop(1) << endl;
    cout << "Popped element from stack 0 is " << ks.pop(0) << endl;
	
	return 0;
	
}