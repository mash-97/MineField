#include <stdio.h>
#define MAX 10

int used[MAX], number[MAX];
int numbers_array[MAX];

void d(int *array, int length, int div)
{
	int s=0, e=length-1;
	if(div==1){ ++s, ++e;};
	
	for(int i=s; i<=e; i++) printf("%d ", array[i]);
	puts("");
}

void p(int at, int n)
{
	if(at==n+1)
	{
		d(number, n, 1);
		return;
	}
	
	for(int i=1; i<=n; i++)
	if(!used[i])
	{
		used[i]=1;
		number[at]=numbers_array[i-1];
		p(at+1, n);
		used[i]=0;
	}
}


int main()
{
	int n;
	printf("n:: ");		scanf("%d", &n);
	printf("Enter %d numbers:: ", n); for(int i=0; i<n; i++) scanf("%d", &numbers_array[i]);
	printf("Printing Combination of : "); d(numbers_array, n, 0);
	//printf("Printing permutation(%d):\n", n);
	p(1, n);
	puts("");
	puts("");
	main();
}
