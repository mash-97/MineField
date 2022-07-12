#include <iostream>
using namespace std;

template <class T>
T getMax(T a, T b)
{
	return (a>b)?a:b;
}

template <class T, class U>
U get_max(T a, U b)
{
	return (a>b)?a:b;
}

int main()
{
	int i=5, j=6, k;
	long a=2, b=3, c;
	
	k = getMax(i,j);
	c = getMax(a,b);
	
	//~ l = getMax(a,i);
	//~ d = getMax(a,i);
	
	cout << "k: "<<k<<endl;
	cout << "c: "<<c<<endl;
	cout << "l: "<<get_max(i, a)<<endl;
	
	return 0;
}
