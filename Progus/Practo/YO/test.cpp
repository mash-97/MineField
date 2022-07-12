#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	long long int n, p, w, d, pp;
	long long int x, y;
	
	scanf("%lld%lld%lld%lld", &n, &p, &w, &d);
	pp = p;
	x = p/w;
	p = p - (x*w);
	
	y = p/d;
	p = p - (y*d);
	
	if(p!=0) 
	{
		if(pp%d==0 && pp/d<=n)
			printf("%lld %lld %lld\n", (long long int)0, pp/d, (n-(pp/d)));
			
		else 
			printf("%d\n", -1);
	}
	else
		printf("%lld %lld %lld\n", x, y, (n-(x+y)));

	return 0;
	
}
