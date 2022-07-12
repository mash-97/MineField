#include <stdio.h>
#include <time.h>

int used[20], number[20];

// call with: permutation(1, n)
// make sure, all the entries in used[] is 0
void permutation(int at, int n)
{
	if(at == n+1)
	{
		for(int i=1; i<=n; i++) printf("%d ", number[i]);
		printf("\n");
		return;
	}
	
	for(int i=1; i<=n; i++) if(!used[i])
	{
		used[i] = 1;
		number[at] = i;
		permutation(at+1, n);
		used[i] = 0;
	}
}

int main()
{
	int n;
	printf(":: ");scanf("%d", &n);
	
	clock_t s = clock();
	permutation(1, n);
	clock_t e = clock();
	printf("Execution time for (n:%d): %.6f\n", n, (double)(e-s)/CLOCKS_PER_SEC);
	main();
	return 0;
}
