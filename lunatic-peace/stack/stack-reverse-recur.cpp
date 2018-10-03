/ C++ code to reverse a 
// stack using recursion
#include<bits/stdc++.h>
using namespace std;
 
void insert_at_bottom(stack <int> &s, int top) 
{
	int temp;
	if (s.empty()) {
		s.push(top);
		return;
	}
	temp = s.top();
	s.pop();
	insert_at_bottom(s, top);
	s.push(temp);
}
void reverse_stack (stack <int> &s)
{
	int data;
	if (s.empty()) 
		return;
	data = s.top();
	s.pop();
	reverse_stack(s);
	insert_at_bottom(s, data);
}
void print_my_stack(stack <int> st)
{
	while (!st.empty()) {
		printf ("%d \t", st.top());
		st.pop();
	}
	cout << "\n";
}
int main ()
{
	stack<int> my_stack;
	my_stack.push(5);
	my_stack.push(4);
	my_stack.push(3);
	my_stack.push(2);
	my_stack.push(1);
	cout << "Before reversal Elements: \n";
	print_my_stack(my_stack);
	reverse_stack (my_stack);
	cout << "After reversal Elements: \n";
	print_my_stack(my_stack);
	return 0;
	
}
