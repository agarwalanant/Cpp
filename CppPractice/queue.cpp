//
// Created by Anant Agarwal on 7/25/18.
//

#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node* next;
};

class Queue
{
public:
    Node* top = nullptr;
    Node* end = nullptr;
    bool push(int);
    int pop();
    bool is_empty();
    int count =0;
};

bool Queue::push(int data){
    auto newtop = new Node;
    if (top == nullptr)
    {
        newtop->data = data;
        newtop->next = nullptr;
        top = newtop;
        count++;
    }

}


int main(){


}

