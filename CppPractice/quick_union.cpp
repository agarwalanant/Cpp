#include <iostream>
#include<vector>
using namespace std;
std::vector<int> v;
bool populate(int n)
{
	for (int i = 0; i < n; ++i)
	{
		v.push_back(i);
	}
}

int root(int i)
{
	while(i != v.at(i))
	{
		i= v.at(i);
	}
	return i;
}

bool find(int first, int second)
{
	return (root(first)==root(second));
}

void un(int first, int second)
{
	int i = root(first);
	int j = root(second);

	v.at(i)=j;
}

int main(int argc, char const *argv[])
{
	populate(20);
	un(1,3);
	un(4,5);
	un(3,4);
	cout<<"find 1 8 = "<<find(1,8)<<endl;

	cout<<"find 1 5 = "<<find(1,5);
	return 0;
}
