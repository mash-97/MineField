#include <bits/stdc++.h>
using namespace std;

//Function to compute xor of 1 to n
long computeXor(const int n)
{
	//Modulus operations are expensive on every computer.
	//n&3 will be equivalent to n%4
	switch(n&3)
	{
		case 0: return n;	//if n is multiple of 4
		case 1: return 1;	//if n%4 gives remainder 1
		case 2: return n+1; //if n%4 gives remainder 2
		case 3: return 0;	//if n%4 gives remainder 3
	}
}

//Driver code
int main()
{
	int n;
	scanf("%d", &n);
	cout << computeXor(n);

	main();
	return 0;
}
