#include <stdio.h> 
#include <math.h>
#define swap(a,b) { int c = a; a = b; b = c;}


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
	if(array_1[0][j])
	{
		value = array_1[0][j]*pow(-1, j);
		
		produceSubMatrixOf(n, array_1, 0, j, array_2);
		value *= determinantOf(n-1, array_2);
		//printf(" value = %d\n", value);
		rvalue += value;
	}
	return rvalue;
}

void sTranspose(int n, int matrix[n][n])
{
	for(int row=0, column=0; row<n; ++row,column++)
		for(int i=row+1; i<n; i++) swap(matrix[row][i], matrix[i][column]);
}

void nTranspose(int n, int m, int matrix[n][m], int transpose[m][n])
{
						for(int i=0; i<n; i++)
						for(int j=0; j<m; j++)
					transpose[j][i] = matrix[i][j];
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
	int n;
	printf("n :: ");
	scanf("%d", &n);
	
	int Matrix[n][n];
	printf("Matrix[%d][%d]::\n", n, n);
	for(int i=0; i<n; i++) for(int j=0; j<n; j++) scanf("%d", &Matrix[i][j]);
	
	printf("|Matrix|: %d\n", determinantOf(n, Matrix));
	
	sTranspose(n, Matrix);
	
	puts("");
	displayMatrix(n, n, Matrix);
	
	printf("|Matrix^t|: %d\n", determinantOf(n, Matrix));
	/*
	int m;
	puts("");
	printf("n:m :: ");			scanf("%d*%d", &n, &m);
	
	int matrix[n][m];
	int Transpose[m][n];
	
	printf("Matrix[%d][%d]::\n", n, m);
	for(int i=0; i<n; i++) for(int j=0; j<m; j++) scanf("%d", &matrix[i][j]);
	
	nTranspose(n, m, matrix, Transpose);
	
	puts("");
	displayMatrix(m, n, Transpose);
	puts("");*/
	return 0;
}
