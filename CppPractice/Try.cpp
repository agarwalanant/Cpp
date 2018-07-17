#include<iostream>
#include<vector>

using namespace std;

vector<int> v;

bool find(int first,int sencond)
{
	return (v[first]== v[sencond])

}


void union(int first,int sencond)
{
	for (int i = 0; i < v.size(); ++i)
	{
		if (v.at(i)==v[first])
		{
			v[i]=v[sencond];
		}
	}

	
}

bool populate(
{
	for (vector<int>::iterator i = v.begin(); i != v.end(); ++i)
	{
		v.push_back(i);
	}
}


void main(int argc, char const *argv[])
{

	std::vector<int> v;
	
	return 0;
}