#include <iostream>
using namespace std;

void swap(int &a, int &b, int c = 10)
{
	int temp = a;
	a = b;
	b = temp+c;
}


int main()
{
	int a = 5;
	int b = 10;
	
	cout << "Before swap: a:: "<< a << "  b:: " << b <<endl;
	
	swap(a,b, 5);
	
	cout << "After swap: a:: "<< a << "   b:: "<< b <<endl;
	
	return 0;
}
