#include <iostream>

using namespace std;

class Node()
{
	int data;
	Node next;
}


public pop(Node node)
{
	int data = Node.data;

	node=node.next;

	return data;
}


public push(Node node, int data)
{
	Node old = node;

	head = new Node();

	head.data=data;

	head.next = old;
}



int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}
