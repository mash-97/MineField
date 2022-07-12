#include <iostream>
#include <cstdio>

using namespace std;

#define ulli unsigned long long int
ulli array[1000];
int count[1000];
int wcount[1000];
int wwcount(int n)
{
	if(n<0) return 0;
	wcount[n]++;
	if(n==0 || n==1) return 1;
	return wwcount(n-1)+wwcount(n-2);
}
ulli way(int n, int m)
{
	if(n<0) return 0;
	if(n==0 || n==1) return 1;
	ulli result = 0;
	for(int i=1; i<=m; i++)
	{
		if(n-i<0) break;
		if(array[n-i]==0) 
		{
			printf("n: %d, i: %d\n", n, i);
			count[n-i]++;
			array[n-i] = way(n-i, m);
		}
		result += array[n-i]%100;
	}
	return result%100;
}

ulli away(int n, int m)
{
	ulli a[n+1];
	a[0] = a[1] = 1;
	for(int i=2; i<=n; i++)
	{
		ulli sum = 0;
		for(int j=1; j<=m; j++)
		{
			if(i-j<0) break;
			sum += a[i-j]%100;
		}
		a[i] = sum%100;
	}
	
	return a[n]%100;
}

int main()
{
	array[0] = array[1] = 1;
	for(int i=2; i<1000; i++) 
		wcount[i] = array[i] = count[i] = 0;
	int n, m;
	scanf("%d%d", &n, &m);
	
	printf("%llu\n", way(n, m));
	printf("%llu\n", away(n, m));
	printf("%d\n", wwcount(n));
	for(int i=0; i<n; i++) 
		printf("%d::%d ", count[i], wcount[i]);
	puts("");
	puts("");
	main();	
	return 0;
}
