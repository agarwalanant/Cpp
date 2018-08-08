//
// Created by vin on 8/8/18.
//

#include "iostream"

using namespace std;


int lis(char *X, char* Y, int n, int m)
{
    int dp[n+1][m+1];
    int i,j;
    for ( i = 0; i <= n; i++) {
        for ( j = 0; j <= m ; j++) {
            if(i ==0)
                dp[i][j] = j;
            if(j == 0)
                dp[i][j] = i;

            if(X[i-1]==Y[j-1])
            {
                dp[i][j] = dp[i-1][j-1];
            }

            else
                dp[i][j] = 1+ min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));
        }

    }

    return dp[n][m];
}

int main()
{
    char a[]={'M','A','R','C','H'};
    char b[]={'C','A','R','T'};

    cout<< lis(a,b,4,5);
    return 0;
}

