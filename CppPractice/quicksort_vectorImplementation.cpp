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

bool knuth(vector<int> data)
{

    int size = data.size();
    int i=0;
    while (i < size)
    {
        int ranodm = rand()%size;
        swap(&data.at(i),&data.at(ranodm));
        i++;

    }
}

int partition(vector<int> data, int low, int high)
{
    int i = low, j = high +1;
    while (true)
    {
        while (data.at(++i)<data.at(low))
            if(i == high)
                break;
        while(data.at(low) < data.at(--j))
            if(j == low)
                break;
        if(i >= j)
            break;
        swap(&data.at(i),&data.at(j));
    }

    swap(&data.at(low),&data.at(j));
    return j;
}

void sort(vector<int> data, int low, int high)
{
    if(high < low) return;
    int j = partition(data, low, high);
    sort(data, low, j-1);
    sort(data, j, high);
}

void sort(vector<int> data)
{
    int size = data.size();
    knuth(data);
    sort(data, data.begin(), data.end());// how to define this function definition
}




int main()
{
    cout<<"Quick Sort "<<endl;

    vector<int> vector1 = {9,8,7,6,5,4,3,2,1,0};

    sort(vector1);

    return 0;


}