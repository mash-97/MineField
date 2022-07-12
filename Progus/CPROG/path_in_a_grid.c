#include <stdio.h>
#define max(a,b) a>b?a:b
#define NEG -11111111

int f(int r, int c, int n, int grid[][n], int farray[][n])
{
	if(n==0) return NEG;
	if(n==1) return grid[0][0];
	if(r==n-1 && c==n-1) return grid[n-1][n-1];
	
	return 0;
}

void copy_array(int n, int *a1, int *a2)
{
	for(int i=0; i<n; i++) a2[i] = a1[i];
}

int max_sum = NEG;
int max_array[100];

void nf(int r, int c, int sum, int n, int grid[][n], int indx, int *farray)
{
	if(n==0) return;
	if(n==1) {max_sum = grid[0][0]; return;}
	
	farray[indx] = grid[r][c];
	if(r==n-1 && c==n-1) 
	{
		sum += grid[n-1][n-1];
		if(max_sum<sum) 
		{
			copy_array(indx+1, farray, max_array);
			max_sum=sum;
		}
		return;
	}
	
	if(r>=0 && r<n && c>=0 && c<n)
	{
		if(r+1<n)
			nf(r+1, c, sum+grid[r][c], n, grid, indx+1, farray);
			
		if(r+1<n)
			nf(r, c+1, sum+grid[r][c], n, grid, indx+1, farray);
	}
}

void d(int n, int *a)
{
	for(int i=0; i<n; i++) printf("%d ", a[i]);
	puts("");
}

int main()
{
	int n;
	scanf("%d", &n);
	
	int grid[n][n];
	int farray[2*n];
	
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
		{
			scanf("%d", &grid[i][j]);
			//farray[i][j] = NEG;
		}
	
	nf(0, 0, 0, n, grid, 0, farray);
	printf("answer: %d\n", max_sum);
	d(2*n-1, max_array);
	return 0;
}

//~ 6 9 8 4
//~ 10 11 3 9
//~ 6 5 0 8
//~ 4 3 2 1

