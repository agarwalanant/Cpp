//
// Created by Anant Agarwal on 8/8/18.
//

#include "iostream"

using namespace std;


int Knap (int Wt[], int v[], int n, int W)
{
    int K[n+1][W+1];
    int i,w;
    for ( i = 0; i <=n ; i++) {
        for (w = 0; w <= W; w++) {
            if(i ==0 || w==0) K[i][w]=0;

            else if(Wt[i-1]<= w)
                K[i][w] = max(v[i-1]+K[i-1][w-Wt[i-1]],K[i-1][w]);
            else
                K[i][w] = K[i-1][w];

        }
    }

    return K[n][W];
}

int main()
{

    int val[] = {60,100,120};
    int wt[]= {10,20,30};
    int n =3;
    cout<<Knap(wt,val,3,50);

    return 0;
}

