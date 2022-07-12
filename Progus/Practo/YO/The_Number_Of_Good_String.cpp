#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int checkBit(int c, int n, int pos)
{
	if(pos > 31) return !c;
	return !((c) ^ ((n&(1<<pos))>>pos));
}

int numG(char *string, int n)
{
	int count = 0;
	for(int i=1; i<=n; i++)
	{
		int j=0; 
		while(j<i-1) j+=1;
		while(j<n)
		{
			int flag = true;
			for(int k=1; k<=i; k++)
			{
				if(!checkBit((int)(string[j-k+1]-'0'), i, k-1))
				{
					flag = false;
					break;
				}
			}
			if(flag) count++;
			j+=1;
		}
	}
	return count;
}

int main()
{
	int n;
	scanf("%d", &n);
	char string[200005];
	while(n--)
	{
		scanf(" %s", string);
		printf("%d\n", numG(string, (int)strlen(string)));
	}
	return 0;
}
