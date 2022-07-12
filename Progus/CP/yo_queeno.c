#include <stdio.h>

int n;
int r1[15];
int r2[30];
int r3[30];
int array[15][15];
//~ void dis()
//~ {
	//~ for(int i=0; i<n; i++)
		//~ for(int j=0; j<n; j++) printf("%d%c", array[i][j], " \n"[j==n-1]);
//~ }

//~ void dispo(int A[][n], int r, int c)
//~ {
	//~ printf("array[%d][%d]: %d\n", r, c, A[r][c]);
//~ }
	


int count = 0;


//~ int checknos(int x, int y)
//~ {
	//~ if(array[x][y]) return 0;
	//~ for(int i=0; i<n; i++)
	//~ {
		//~ if(array[x][i]==1 || array[i][y]==1) return 0;
		//~ else if((x-i>=0 && y-i>=0) && array[x-i][y-i]==1) return 0;
		//~ else if((x-i>=0 && y+i<n)  && array[x-i][y+i]==1) return 0;
		//~ else if((x+i<n  && y-i>=0) && array[x+i][y-i]==1) return 0;
		//~ else if((x+i<n  && y+i<n)  && array[x+i][y+i]==1) return 0;
	//~ }
	//~ return 1;
//~ }

void yo_queeno(int r)
{
	//printf("r: %d\n", r);
	//dis(array, n);
	if(r==n)
	{
		//dis();
		count++;
		return;
	}

	for(int c=0; c<n; c++)
	if(!r1[c] && !r2[r+c] && !r3[(n-1)+c-r])
	{
		if(array[r][c]==5) continue;
		r1[c] = r2[r+c] = r3[(n-1)+c-r] = 1;
		yo_queeno(r+1);
		r1[c] = r2[r+c] = r3[(n-1)+c-r] = 0;
	}
}
	
void disp(int n, int array[][n])
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
	int array[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
	disp(3, array);
	static int yo = 1;
	count = 0;
	scanf("%d", &n);
	if(n==0) return 0;
	char s[n+2];
	for(int i=0; i<n; i++)
	{
		scanf(" %s", s);
		for(int j=0; j<n; j++)
		{
			if(s[j] == '*') array[i][j] = 5;
			else array[i][j] = 0;
		}
	}
	yo_queeno(0);
	printf("Case %d: %d\n", yo, count);
	yo++;
	main();
}
