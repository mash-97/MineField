#include <stdio.h>
#define MAX 10

int number[MAX], used[MAX];
int array[MAX];

void display(int *array, int length)
{
	for(int i=1; i<=length; i++) printf("%d ", array[i]);
	puts("");
}

void permute(int at, int n, int k)
{
	if(at==k+1)
	{
		display(number, k);
		return;
	}
	
	for(int i=1; i<=n; i++)
	if(!used[i])
	{
		used[i]=1;
		number[at] = array[i-1];
		permute(at+1, n, k);
		//used[i]=0; 
	}
}

int main()
{
	int n, k;
	printf("n k:: ");	scanf("%d %d", &n, &k);
	printf("array:: "); for(int i=0; i<n; i++) scanf("%d", &array[i]);
	printf("Displaying permutation of 1..%d:\n", n);
	permute(1, n, k);
	
	main();
}
