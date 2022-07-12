#include <stdio.h>
#include <math.h>
#include <time.h>

int matrix[20][20];

void produceSubMatrixOf(int n, int array_1[n][n], int x, int y, int array_2[n-1][n-1])
{
	int i, j, k, l;
	//printf("array_1[%d][%d] = %d\n", x, y, array_1[x][y]);
	for(i=0, k=0; i<n; i++)
	if(i!=x)
	{
		for(j=0, l=0; j<n; j++)
		if(j!=y)
		{
			array_2[k][l++] = array_1[i][j];
			//printf("%d ", array_2[k][l-1]);
		}
		//puts("");
		k++;
	}
}

int determinantOf(int n, int array_1[][n])
{
	if(n==2) return((array_1[0][0]*array_1[1][1]) - (array_1[0][1]*array_1[1][0]));
	
	//printf("address 1 %p\n", array_1);
	int array_2[n-1][n-1];
	//printf("address 2 %p\n", array_2);
	int j, value,  rvalue = 0;
	
	for(j=0; j<n; j++)
	{
		value = array_1[0][j]*pow(-1, j);
		
		produceSubMatrixOf(n, array_1, 0, j, array_2);
		value *= determinantOf(n-1, array_2);
		//printf(" value = %d\n", value);
		rvalue += value;
	}
	return rvalue;
}
	
int main()
{
	int n; 
	clock_t s;
	clock_t e;
	
	printf("n:: ");
	scanf("%d", &n);
	
	int matrix[n][n];
	printf("Matrix:: \n");
	for(int i=0; i<n; i++)
	for(int j=0; j<n; j++)
	scanf("%d", &matrix[i][j]);
	
	s = clock();
	printf("Determinant:: %d\n", determinantOf(n, matrix));
	e = clock();
	
	printf("Execution time: %.6lf\n", (double)(e-s)/CLOCKS_PER_SEC);
	main();
	return 0;
}
