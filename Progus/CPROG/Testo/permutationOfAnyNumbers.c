#include <stdio.h>
#define MAX 20

int number[MAX];
int n, k;
int max, min;

int displaysum(int *array, int length);

void combination(int at, int last)
{
	if(at == k+1) 
	{
		
		int s = displaysum(number, k); 
		if(max < s) max = s;
		if(min > s) min = s;
		return;
	}
	for(int i=last+1; i <= n-k+at; i++)
	{
		number[at] = i;
		combination(at+1, i);
	}
	
}

int main()
{
	max = 0;
	min = 2147483647;
	
	printf("n:k ::  ");
	scanf("%d%d", &n, &k);
	
	combination(1, 0);
	
	printf("max : %d\n", max);
	printf("min : %d\n", min);
	puts("");
	main();
}
	
	







int displaysum(int *array, int length)
{
	int s = 0;
	for(int i=1; i <= length; i++){ s+=array[i]; printf("%d ", array[i]);}
	puts("");
	return s;
}
