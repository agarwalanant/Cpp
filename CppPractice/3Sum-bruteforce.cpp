#include <iostream>
#include <vector>
#include <time.h>

using namespace std;
int count(vector<int> a)
{
	int n = a.size();
	int count=0;
	clock_t t1,t2;
	t1=clock();
	for (int i = 0; i < n; ++i)
	{
		for (int j = i+1; j < n; ++j)
		{
			for (int k = j+1; k < n; ++k)
			{
				if (a[i]+a[j]+a[k]==0)
				{
					count++;
				}
			}
		}
	}
	t2=clock();
	float time=((float)t2-(float)t1)/CLOCKS_PER_SEC;
	cout<<"Time"<<time<<"\n";
	return count;
}
int main(int argc, char const *argv[])
{
	std::vector<int> v = {0,1,2,3,-3,4,-2,10,-5,7,12,6,-8};
	int res = count(v);
	cout<<"Result"<<"   "<<res;
	//cout<<res<<"";
	return 0;
}