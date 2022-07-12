#include <stdio.h>

int matrixMultipicate(int r1, int c1, int A[r1][c1], int r2, int c2, int B[r2][c2], int AB[r1][c2])
{
	if(c1!=r2) return 0;
	
	for(int i=0; i<r1; i++)
	for(int j=0; j<c2; j++)
	{
		int sum = 0;
		for(int k=0; k<c2; k++) sum += A[i][k] * B[k][j];
		AB[i][j] = sum;
	}
	
	return 1;
}

void displayMatrix(int r, int c, int matrix[r][c])
{
	for(int i=0; i<r; i++)
	{
		for(int j=0; j<c; j++) printf("%5d ", matrix[i][j]);
		puts("");
	}
}

int main()
{
	int r1, c1;
	int r2, c2;
	
	printf("A: ");
	scanf("%d*%d", &r1, &c1);
	int A[r1][c1];
	
	for(int i=0; i<r1; i++)
		for(int j=0; j<c1; j++) 
			scanf("%d", &A[i][j]);
		
	printf("\nB: ");
	scanf("%d*%d", &r2, &c2);
	int B[r2][c2];
	
	for(int i=0; i<r2; i++)
		for(int j=0; j<c2; j++)
			scanf("%d", &B[i][j]);
			
	int AB[r1][c2];
	
	puts("");
	if(!matrixMultipicate(r1,c1,A, r2,c2,B, AB)) printf("Invalid Dimension!!!\n");
	
	else
	{
		printf("AB: %d*%d\n", r1, c2);
		displayMatrix(r1, c2, AB);
	}
	
	return 0;
}
