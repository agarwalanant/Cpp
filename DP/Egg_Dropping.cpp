//
// Created by Anant Agarwal on 8/8/18.
//

#include "iostream"

using namespace std;

int ER(int n,int k)
{
    if(k ==1 || k== 0) return k;

    if(n ==1)
        return k;

    int min = INT32_MAX,x,res;

    for ( x = 1; x <= k; ++x) {
         res = max(ER(n-1,x-1),ER(n,k-x));

        if(res < min)
            min = res;
    }

    return min+1;
}

int ED(int n,int k)
{
    int egg[n+1][k+1];
    int res,i,j,x;
//1 trial fpr 1 floor and - trial for 0 floor
    for ( i = 1; i <=n ; i++) {
        egg[i][1]=1;
        egg[i][0]=0;
    }

    for ( j = 1; j <=k  ; j++) {
        egg[1][j] = j;
        egg[0][j] = INT32_MIN;
    }

    for ( i = 2; i <= n; ++i) {
        for (j = 2; j <= k; ++j) {
            egg[i][j] = INT32_MAX;
            for ( x = 0; x < j; ++x) {
                res =1+ max(egg[i-1][x-1],egg[i-1][j-x]);
                if(res < egg[i][j])
                    egg[i][j] = res;

            }
        }

    }
    return egg[n][k];
}

int main()
{
 //cout<<ER(20,66); 
 cout<<ED(20,66 );
    return 0;
}
