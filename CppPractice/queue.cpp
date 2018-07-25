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
    Node* prev;
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
    if(top == nullptr)
    {
        newtop->data = data;
        newtop->next = nullptr;
        top = newtop;
        end = top;
        end->next = nullptr;
        count++;
    }
    else
    {
        newtop->data = data;
        newtop->next = nullptr;
        end->next = newtop;
        end = newtop;
        end->next = nullptr;
        count++;
    }


    }int Queue::pop() {
        if (top == end)
        {
            cout<<"Empty Queue "<<endl;
            return 0;
        }
        else
        {
            int data = top->data;
            Node* temp = top;
            top->next = top;
            delete(temp);
            return data;

        }

}

bool Queue::is_empty() {
    if(top== end)
        return true;
    else
        return false;
}

int main(int argc, char const *argv[]) {
    auto s1 = new (Queue);
    s1->push(1);
    s1->push(3);
    cout << "popped " << s1->pop() << endl;
    s1->pop();
    s1->pop();
}
