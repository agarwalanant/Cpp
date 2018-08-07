//
// Created by vin on 8/7/18.
//

#include "iostream"

using namespace std;

int fib(int n)
{
    int f[n+1];
    int i;
    f[0]=0;f[1]=1;
    for ( i = 2; i <=n ; ++i) {
        f[i] = f[i-1] + f[i-2];
    }

    return f[n];

}

int main()
{
cout<<fib(12);

    return 0;
}
