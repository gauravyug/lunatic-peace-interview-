#include "stack.h"

Stack::Stack(int size)
{
        arr = new int[size];
        capacity = size;
        top = -1;
}

bool Stack::isFull()
{
        return top == capacity - 1;	// or return size() == capacity;
}

bool Stack::isEmpty()
{
        return top == -1;	// or return size() == 0;
}

int Stack::pop()
{
// check for stack underflow
	if (isEmpty())
	{
		cout << "UnderFlow\nProgram Terminated\n";
		exit(EXIT_FAILURE);
	}

	cout << "Removing " << peek() << endl;

	// decrease stack size by 1 and (optionally) return the popped element
	return arr[top--];
}

int Stack::peek()
{
        if (!isEmpty())
		return arr[top];
	else
		exit(EXIT_FAILURE);
}

void Stack::push(int item)
{
        if (isFull())
	{
		cout << "OverFlow\nProgram Terminated\n";
		exit(EXIT_FAILURE);
	}

	cout << "Inserting " << item << endl;
	arr[++top] = item;
}



// Utility function to return the size of the stack
int Stack::size()
{
	return top + 1;
}




int main()
{
	Stack pt(3);

	pt.push(1);
	pt.push(2);

	pt.pop();
	pt.pop();

	pt.push(3);

	cout << "Top element is: " << pt.peek() << endl;

	cout << "Stack size is " << pt.size() << endl;

	pt.pop();

	if (pt.isEmpty())
		cout << "Stack Is Empty\n";
	else
		cout << "Stack Is Not Empty\n";

	return 0;
}
