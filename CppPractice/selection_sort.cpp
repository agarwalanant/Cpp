#include <iostream>
#include<array>
#include<iterator>
using namespace std;


void swap(int *first, int *second)
{
	int temp = *first;
	*first = *second;
	*second = temp;
}

void sort(int data[],int length)
{
	//int length = sizeof(data) / sizeof(data[0]);

	for (int i = 0; i < length; ++i)
	{
		 int min =i;
		for (int j = i+1; j < length; ++j)
		{
			if(data[j]<data[min])
			{
				min = j;

			}
			swap(&data[i],&data[j]);
		}
	}
}


int main(int argc, char const *argv[])
{
	int arr[]= {5,4,3,2,1};
	sort(arr,5);
	for(int i =0 ;i < 5;i++)
	{
        cout<<arr[i];
	}
	return 0;
}
