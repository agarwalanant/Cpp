//
// Created by Anant Agarwal on 7/28/18.
//

#include "iostream"
#include "cstdlib"
using namespace std;


void swap(int *first, int *second)
{
    int temp = *first;
    *first = *second;
    *second = temp;
}

bool knuth(int data[], int length)
{

    int i=0;
    while (i < length)
    {
        int ranodm = rand()%8;
        swap(&data[i],&data[ranodm]);
        i++;

    }
}


int main(int argc, char const *argv[])
{
    int array[] = {1,2,3,4,5,6,7,8,9,0};
    knuth(array,10);

    for(int i=0; i< 10 ; i++)
    {
        cout<<array[i]<<endl;
    }
    return 0;
}