#include <iostream>
#include <cstdio>

using namespace std;
#define NEG -111111111

int farray[10][10];
int f(int r, int c, int n, int grid[][n])
{
	if(n==0) return 0;
	if(n==1) return grid[0][0];
	if(r==n-1 && c==n-1) return grid[n-1][n-1];
	
	if(r>=0 && r<=n-1 && c>=0 && c<=n-1)
	{
		if(farray[r][c]!=NEG) return farray[r][c];
		
		int d = NEG;
		if(r+1 < n-1) d = f(r+1, c, n, grid);
		
		int r = NEG;
		if(c+1 < n-1) r = f(r, c+1, n, grid);
		
		farray[r][c] = max(d, r)+grid[r][c];
	}
	return NEG;
}


int main()
{
	int n;
	cin>>n;
	int grid[n][n];
	//int farray[n][n];
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
		{
			cin>>grid[i][j];
			farray[i][j] = NEG;
		}
	
	cout<<"answer: "<<f(0, 0, n, grid)<<endl;
	
	return 0;
}
	
	
	
