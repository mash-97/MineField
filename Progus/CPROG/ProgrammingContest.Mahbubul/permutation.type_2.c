#include <stdio.h>

int number[20];
int n, k;



void display(int *array, int length);

// call with: combination(1, 0)
void combination(int at, int last)
{
	if(at == k+1) {display(number, k); return;}
	for(int i=last+1; i<=n-k+at; i++)
	{
		number[at] = i;
		combination(at+1, last-1);
	}
}

int main()
{
	printf("n:k :: ");
	scanf("%d%d", &n, &k);
	
	combination(1, 0);
	
	puts("");
	main();
}

void display(int *array, int length)
{
	for(int i=1; i<=length; i++) printf("%d ", array[i]);
	puts("");
}
