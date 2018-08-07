//
// Created by vin on 8/7/18.
//


#include "iostream"

using namespace std;


int lcs(char *X, char *Y, int m, int n)
{
    int l[m+1][n+1];
    int i, j;

    for ( i = 0; i <m ; ++i) {
        for ( j = 0; j < n ; ++j) {

            if (i ==0 || j== 0 )
                l[i][j] =0;

            else if(X[i-1] == Y[i-1])
                l[i][j] = l[i-1][j-1]+1;
            else
                l[i][j] = max(l[i-1][j],l[i][j-1]);
        }

    }

    return l[m][n];
}

int main()
{

    return 0;
}
