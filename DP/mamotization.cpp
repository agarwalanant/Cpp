//
// Created by vin on 8/7/18.
//

#include "iostream"

using namespace std;

int lookup[100];

void ini()
{
    for (int i = 0; i < 100 ; i++) {
        lookup[i] = INT16_MIN;

    }
}

int fib(int n)
{
    ini();
    //cout<<"n "<<n<<endl;
    if(lookup[n] == INT16_MIN)
    {
        if(n <= 1)
        {
            lookup[n] = n;
       //     cout<<"n1 "<<n<<endl;
        }
        else
        {
        //    cout<<"Exe"<<endl;
            lookup[n] = fib(n-1) + fib(n-2);
           // cout<<lookup[n];
        }
    }

    return lookup[n];
}
int main()
{
    cout<<fib(8);
    return 0;
}