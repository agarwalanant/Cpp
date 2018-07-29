//
// Created by vin on 7/29/18.
//

#include "iostream"
#include "vector"

using namespace std;

void swap(int *first, int *second)
{
    int temp = *first;
    *first = *second;
    *second = temp;
}

bool knuth(int data[], int length)
{
    int size = size(data);
    int i=0;
    while (i < length)
    {
        int ranodm = rand()%size;
        swap(&data[i],&data[ranodm]);
        i++;

    }
}

int partition(int data[], int low, int high)
{
    int i = low, j = high +1;
    while (true)
    {
        while (data[++i]<data[low])
            if(i == high)
                break;
        while(data[low] < data[--j])
            if(j == low)
                break;
        if(i >= j)
            break;
        swap(&data[i],&data[j]);
    }

    swap(&data[low],&data[j]);
    return j;
}

void sort(int data[], int low, int high)
{
    if(high < low) return;
    int j = partition(data, low, high);
    sort(data, low, j-1);
    sort(data, j, high);
}

void sort(int data[])
{
    int size = size(data);
    knuth(data,size);
    sort(data, 0, size -1);
}




int main()
{
cout<<"Quick Sort "<<endl;

    int array[] =  {0,9,8,888,6,5,56,3,2,1};
    cout<<"start"<<endl;
//    sort(array);
    cout<<"middle"<<endl;
    int size = size(array);
    cout<<size<<endl;
//    for (int i = 0; i < 10 ; ++i) {
//        cout<<array[i]<<" ";
//    }
//    cout<<"end"<<endl;
}