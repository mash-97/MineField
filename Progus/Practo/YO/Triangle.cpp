#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	
	if(a!=b && b!=c && a!=c)
		printf("Bad Triangle\n");
	else if((a!=b && b==c) || (a!=b && a==c) || (a!=c && a==b))
		printf("Isosceles Triangle\n");
	else
		printf("Equilateral Triangle\n");
	
	return 0;
}
