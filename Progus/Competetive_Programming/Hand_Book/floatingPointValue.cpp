#include <bits/stdc++.h>
using namespace std;

int main()
{
	double a, b;
	long double c = 0.3*3+0.1;
	a = 0.3*3+0.1;
	b = 0.4*3+0.1;
	double d = abs(b-a);
	printf("abs: %0.10lf\n", d);
	printf("%0.20lf\n", a);
	printf("%.0lf\n", a);
	printf("%0.22lf\n", b);
	printf("%0.20llf\n", c);
	if(a==b) printf("a and b are equal\n");
	else printf("They are not equal\n");
	
	return 0;
}
