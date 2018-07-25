#include <iostream>

using namespace std;

class Node
{
public:

	int data;
	Node *next;
};

class stacks
{
public:
	Node *top{};
	int count =0;
	int pop();
	bool push(int);
	bool isEmpty();

};
int stacks::pop()
{
	if(top == NULL)
	{
		cout<<"Empty stack"<<endl;
	}
	else
	{
		Node *old = top;

		top = top ->next;
		count--;
		int data = old -> data;
		delete(old);
		count--;
		cout<<"Number of elements in stack "<< count<<endl;
		return data;


	}
}


bool stacks::push(int data)
{
	auto newtop = new Node;

	if (top == nullptr)
	{
		newtop ->data = data;
		newtop ->next = top;
		top = newtop;
		count++;
	}
	else
	{
		newtop ->data= data;
		newtop-> next = top;
		top = newtop;

		count++;
	}
	cout<<newtop ->data<<endl;
	cout<<"number of elements in stack "<<count<<endl;

	return true;
}

bool stacks::isEmpty()
{
	return static_cast<bool>(top == nullptr ? 1 : 0);
}


int main(int argc, char const *argv[])
{
	auto s1 = new (stacks);
	s1 -> push(1);
	s1 -> push(3);
	cout<<"popped "<<s1 -> pop()<<endl;
	s1->pop();
	s1->pop();

	return 0;
}
