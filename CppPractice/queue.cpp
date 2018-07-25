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

bool Queue::push(int data)
{
    auto node = new (Node);
    node->data = data;
    node->next = nullptr;
    if(top == nullptr)
    {
        top = end = node;
        end->next = NULL;
    } else
    {
        end->next = node;
        end = node;
    }

}




int Queue::pop() {
        if (top->next == NULL)
        {
            cout<<"Empty Queue "<<endl;
            top = end = nullptr;

            return 0;
        }
        else
        {
            int data = top->data;
            Node* temp = top;
            top = top->next;
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
