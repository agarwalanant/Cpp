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
    int i=0;
    while (i < length)
    {
        int ranodm = rand()%length;
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
    cout<<"Sort 2"<<endl;
    if(high < low) return;
    int j = partition(data, low, high);
    sort(data, low, j-1);
    sort(data, j, high);
}

void sort(int data[],int size)
{
    cout<<"Sort 1"<<endl;
    knuth(data,size);
    sort(data, 0, size -1);
}




int main()
{
cout<<"Quick Sort "<<endl;

    int array[] =  {0,9,8,888,6,5,56,3,2,1};
    int size = sizeof(array)/ sizeof(*array);
    cout<<"start"<<endl;
   sort(array,size);
    cout<<size<<endl;
    for (int i = 0; i < 10 ; ++i) {
        cout<<array[i]<<" ";
    }
    cout<<"end"<<endl;
}