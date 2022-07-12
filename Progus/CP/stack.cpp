#include <iostream>
#include <vector>

using namespace std;

template <class T>
class Stack
{
	public:
	vector <T> stack_vec;
	
	void push(T a)
	{
		stack_vec.push_back(a);
	}
	
	T pop()
	{
		return stack_vec.pop_back();
	}
};

int main()
{
	Stack <int> a;
	a.push(2);
	a.push(3);
	a.push(4);
	
	for(int i=0; i<3; i++)
	{
		cout << a.stack_vec[i] << endl;
	}
	
	return 0;
}
