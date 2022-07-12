#include <stdio.h>

int used[20], number[20];
int n, k;

void display(int *array, int length)
{
	for(int i=1; i<=length; i++) printf("%d ", array[i]);
	puts("");
}

void permutation(int at)
{
	if(at==k+1)
	{
		display(number, k);
		return;
	}
	
	for(int i=1; i<=n; i++)
	if(!used[i])
	{
		used[i] = 1;
		//if(at-1>0 && number[at-1] > i) break;
		number[at] = i;
		permutation(at+1);
		used[i] = 0;
	}
}

void combination()
{
	for(int i=1; i<=n; i++)
	if(!used[i])
	{
		used[i]=1;
		number[1] = i;
		permutation(2);
	}
	for(int i=1; i<=n; i++) used[i]=0;
}

int main()
{
	printf("n::k::  ");
	scanf("%d%d", &n, &k);
	permutation(1);
	
	main();
}
	
