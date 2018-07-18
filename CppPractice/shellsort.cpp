#include<iostream>

using namespace std;
void swap(int *first, int *second)
{
	int temp = *first;
	*first = *second;
	*second = temp;
}
void insertsort(int data[],int length,int h)
{
	for (int i = 0; i < length; i++)
	{
		int j =i;
		while(data[j]<data[j-1])
		{
			swap(&data[j],&data[j-1]);
			j -=h;

			if (j <0)
			{
				break;
			}
		}
	}
}

void shell(int data[],int length)
{
	insertsort(data,length,13);
	insertsort(data,length,8);
	insertsort(data,length,5);
	insertsort(data,length,1);
}



int main(int argc, char const *argv[])
{
		int arr[]= {5,4,3,2,1};
	shell(arr,5);
	for(int i =0 ;i < 5;i++)
	{
        cout<<arr[i];
	}
	return 0;

}
