//
// Created by vin on 8/7/18.
//

#include "iostream"

using namespace std;

int lis(int arr[],int n)
{
    int *lis,i,j, max =0;
     lis = (int*)malloc(sizeof(int)*n);

    for ( i = 0; i < n ; ++i) {
        lis[i] =1;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i ; ++j) {
            if (arr[i] > arr[j] && lis[i] < lis[j]+1)
                lis[i] = lis[j] +1;
        }
    }

    for (int k = 0; k < ; ++k) {
        if(lis[k] >= max)
            max = lis[k];
    }

    free(lis);

    return max;
}

int main()
{

    return 0;
}