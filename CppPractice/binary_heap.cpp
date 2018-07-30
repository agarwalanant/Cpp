//
// Created by AnantAgarwal on 7/30/18.
//



#include "iostream"
#include "vector"
#include "assert.h"

using namespace std;

class binaryheap

{
public:
    vector<int> data;
    binaryheap()
    {
        data.push_back(0);
    }

    void swim(unsigned long k)// child > parent swim child upwards to correct position
    {
        while (k >1 & (data.at(k/2) < data.at(k)))
        {
            swap(&data.at(k), &data.at(k / 2));
            k = k / 2;
        }
    }


    void swap(int *first, int *second)
    {
        int temp = *first;
        *first = *second;
        *second = temp;
    }

    void insert(int value)
    {
        data.push_back(value);
        //cout<<"Size "<<data.size()<<endl;
        swim(data.size()-1);
    }

    void sink(int k) // if parent < one or both child
    {
        while (2*k < data.size())
        {
            int j = 2*k;
            if(j < data.size() && (data.at(j)< data.at(j+1))) j++; // setting j equal to bigger child
            if(!(data.at(k)< data.at(j))) break;
            swap(&data.at(k),&data.at(j));
        }
    }

    int delMax()
    {
       // assert(!(data.size()==0));

        int max = data.at(1);
        swap(&data.at(1),&data.at(data.size()-1));
        data.pop_back();
        sink(data.at(1));

        return max;

    }

    bool isEmpty()
    {
        return data.size() == 0;
    }

    void view()
    {
        for (int i = 0; i < data.size() ; ++i) {


            cout<<data.at(i)<<endl;
        }
    }

};


int main(){

    binaryheap h1;
    h1.insert(3);
    h1.insert(2);
    h1.insert(1);
    h1.insert(7);
    h1.view();
    cout<<"Delete Element "<<h1.delMax()<<endl;
    cout<<"Delete Element "<<h1.delMax()<<endl;
    cout<<"Delete Element "<<h1.delMax()<<endl;




    return 0;
}