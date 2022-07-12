#include <bits/stdc++.h>
#include <math.h>
#include <stdbool.h>
#define size 1000001
using namespace std;

bool array[size];

void sieve()
{
	int i, j, root;
	
	//marking all as true.  true indicates prime.
	for(i=0; i<=size; i++)array[i]=true;
		
	//marking all even false except 2.
	for(i=4; i<=size; i+=2)array[i]=false;
	
	root = sqrt(size);
	
	for(i=3; i<=root; i+=2)
	{
		if(array[i]==true)
		{
			for(j=i*i; j<=size; j+=2*i)array[j]=false;
		}
	}
}
	
int main()
{
	sieve();
	int T, a, b, count;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &a, &b);
		count=0;
		
		for(int i=a; i<=b; i++)if(array[i]==true)++count;
		printf("%d\n", count);
	}
	return 0;
}
		
