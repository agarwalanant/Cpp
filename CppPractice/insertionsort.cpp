#include<iostream>

using namespace std;
void swap(int *first, int *second)
{
	int temp = *first;
	*first = *second;
	*second = temp;
}


void sort(int data[],int length)
{
	for (int i = 0; i < length; i++)
	{
		int j =i;
		while(data[j]<data[j-1])
		{
			swap(&data[j],&data[j-1]);
			j--;
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
