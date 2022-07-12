#include <stdio.h>

void display(int *array, int length, int _from_zero);

int number[20];
int n, k;
int array[20];
// call with: combination(1,k)

void combination(int at, int left)
{
	//printf("left : %d, n-at+1 : %d\n", left, n-at+1);
	if(left > n-at+1) return;
	//printf("1\n");
	// you can use left == 0 to make it a little bit more faster in such case you don't need following if(left) condition.
	
	if(at == n+1)
	{
		display(number, k, 1);
		return;
	}
	
	if(left)
	{
		number[(k-left)+1] = array[at];
		combination(at+1, left-1);
	}
	
	combination(at+1, left);
}


int main()
{
	printf("n : k :: ");
	scanf("%d%d", &n, &k);
	printf("array :n: ");
	for(int i=1; i<=n; i++) scanf("%d", &array[i]);
	combination(1, k);
	main();
}



























void display(int *array, int length, int _from_zero)
{
	if(_from_zero==0)
		for(int i=0; i<length; i++) printf("%d ", array[i]);
	else
		for(int i=1; i<=length; i++) printf("%d ", array[i]);
	puts("");
}
