//
// Created by Anant Agarwal  on 8/5/18.
//


#include "iostream"

using namespace std;

class Node
{
public:
    long key = INT64_MIN;
    long value = INT64_MIN;
    Node* next = nullptr;
};


class ElementryTable
{

    Node *top;

    long count =0;


public:
    long search(int key)
    {
        if(top->next == nullptr) return INT64_MIN;
        else if(top->key = key) return top->value;
        search(key);
    }

    void insert(long key, long value)
    {
        long found_key = search(key);
        if ( found_key != INT64_MIN)
        {
            top->value = value;
        }
        else
        {
            auto new_node = new Node;
            new_node->key = key;
            new_node->value = value;
            new_node->next = top;
            top = new_node;
            count++;

        }

    }



};



int main()
{


    return  0;
}
