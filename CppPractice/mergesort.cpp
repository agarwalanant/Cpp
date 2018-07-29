//
// Created by Anant Agarwal on 7/28/18.
//

#include "iostream"
#include "assert.h"
#include "array"

using namespace std;

bool isSorted(int data[], int low, int high)
{
    for (int i = low; i < high ; ++i)
    {
        if (data[i+1]<data[i])
            return 0;
    }

    return 1;
}

void merge(int data[],int copy[], int low, int mid, int high)
{
  //  assert(isSorted(data, low, high));
    for (int l = low; l <= high; l++) {
        copy[l] = data[l];
    }

    int i = low,j= mid + 1;
    for (int k = low; k <= high ; k++) {
        if (i > mid) {
            data[k] = copy[j++];
        } else if (j > high) {
            data[k] = copy[i++];
        } else if (copy[j] < copy[i]) {
            data[k] = copy[j++];
        } else {
        data[k] = copy[i++];
    }

    }
 //   assert(isSorted(data, low, high));
}

void sort(int data[], int copy[], int low, int high)
{
    if(high <= low) return;
    int mid = low + (high- low)/2;
    sort(data,copy,low,mid);
    sort(data,copy,mid+1, high);
    merge(data,copy,low,mid,high);
}

void sort(int data[])
{
    int size = sizeof(data)/sizeof(data[0]);
    int copy[size]; // how to find the size of the array
    sort(data,copy,0,10 - 1); // array size
}

int main(int argc, char const *argv[])
{
    cout<<"Merge Sort"<<endl;

    int array[] =  {0,9,8,888,6,5,56,3,2,1};
    sort(array);
    int size = sizeof(array)/sizeof(array[0]);
    for (int i = 0; i < size ; ++i) {
        cout<<array[i]<<" ";
    }



    return 0;
}