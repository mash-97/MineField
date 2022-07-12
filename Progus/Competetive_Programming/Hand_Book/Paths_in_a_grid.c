#include <stdio.h>

void d(int n, int array[][n])
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
			printf("%d ", array[i][j]);
		puts("");
	}
}

int main()
{
	int n; 
	scanf("%d", &n);
	
	int array[n][n];
	for(int i=0; i<n; i++) for(int j=0; j<n; j++) scanf("%d", &array[i][j]);
	
	d(n, array);
	
	return 0;
}
