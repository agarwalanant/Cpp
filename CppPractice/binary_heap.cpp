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
        while ((2*k) <= data.size())
        {
            int j = 2*k;
            if(j < data.size() && (data.at(j) < data.at(j+1))) // ERROR
            {
                j++;
            }// setting j equal to bigger child
            if((data.at(k) >= data.at(j)))
            {
                break;
            }
            swap(&data.at(k),&data.at(j));
            k=j;
        }
    }

    void delMax()
    {
       // assert(!(data.size()==0));

        int max = data.at(1);

        if(data.size() == 0)
            return;
       // view();
       swap(&data.at(1),&data.at(data.size()-1));
//        data.at(1) = data.at((data.size()-1));
//      cout<<"Swap"<<endl;
     //   view();
     //   cout<<"Size "<<data.size()<<endl;
//        view();
      // cout<<"Sink"<<endl;
        sink(1);
        data.pop_back();
//        data.at(data.size() -1) = NULL;
//        view();
//        cout<<"Pop"<<endl;
        return;

    }

    bool isEmpty()
    {
        return data.size() == 0;
    }

    void view()
    {
        for (int i = 0; i < data.size() ; ++i)
        {
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
    h1.insert(9);
    h1.insert(91);
    h1.insert(96);

    h1.view();
    h1.delMax();
    cout<<"Delete 1"<<endl;
    h1.view();
    h1.delMax();
    cout<<"Delete 1"<<endl;
    h1.view();
    h1.delMax();
    cout<<"Delete 1"<<endl;
    h1.view();


//    cout<<"Delete Element "<<h1.delMax()<<endl;
    //h1.view();
  //  cout<<"Delete Element "<<h1.delMax()<<endl;
   // h1.view();
//    cout<<"Delete Element "<<h1.delMax()<<endl;
//    h1.view();
//    cout<<"Delete Element "<<h1.delMax()<<endl;




    return 0;
}