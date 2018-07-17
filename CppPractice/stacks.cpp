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
	Node *top;
	int count =0;

	
};
int stacks::pop()
{
	if(top == NULL)
	{
		cout<<"Empty stack"<<endl;
	}
	else
	{
		node *old = top;

		top = top ->next;
		count--;
		data = old -> data
		delete(old);
		return data;


	}
}


bool stacks::push(Node node, int data)
{
	node *newtop = new Node

	if (top == NULL)
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
	
	return 1;
}

bool stacks::isEmpty()
{
	if(top == NULL)
		return 1;
	else
		return 0;
}


int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}
