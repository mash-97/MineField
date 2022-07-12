#include <stdio.h>

int main()
{
	int n;
	
	printf("n:: ");	scanf("%d", &n);
	
	int array[n], next[n];
	
	printf("array[%d] :: ", n);
	for(int i=0; i<n; i++) scanf("%d", &array[i]);
	
	printf("next[%d] :1..%d: ", n, n);
	for(int i=0; i<n; i++) scanf("%d", &next[i]);
	
	printf("Numbers linked like:: ");
	for(int pos = 0; pos>=0;)
	{
		printf("%d ", array[pos]);
		pos = next[pos];
	}
	printf("\n");
	
	return 0;
}
