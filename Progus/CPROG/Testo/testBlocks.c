#include <stdio.h>

int main()
{
	long int x,m,n,c;
	scanf("%ld",&x);
	m=x;
	x=x/3;
	n=x+x+x;
	c=m-n;
	if(n==m) printf("%ld %ld %ld\n",x,x,x);
	else printf("%ld %ld %ld\n",x,x,x+c);

	return 0;
}
