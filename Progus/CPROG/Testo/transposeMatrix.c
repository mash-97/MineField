#include <stdio.h>
#define swap(a,b) { int c = a; a = b; b = c;}



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
	
	sTranspose(n, Matrix);
	
	puts("");
	displayMatrix(n, n, Matrix);
	
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
	puts("");
	return 0;
}
