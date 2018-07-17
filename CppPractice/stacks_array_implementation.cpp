#include <iostream>
#include <string>

using namespace std;

class stack
{
private:
	string[] s;
	int N =0;
public:
	void fixed_stack(int capacity)
	{
		s new string[capacity];
	}

	bool push(string data)
	{
		s[N++] = data;
		return 1;
	}

	int pop()
	{
		 if(N==0)
		 {
		 	cout<<"Empty Stack"<<endl;
			return 0;
		 }
		 else
		 {
		 	return s[--N];
		 }
		
	}

	bool isEmpty()
	{
		if(N==0)
			return 1;
		else
			return 0;
	}

};

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}