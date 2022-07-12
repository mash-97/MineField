#include <iostream>
#include <queue>
#include <stdio.h>
#include <time.h>

using namespace std;

int grid[10][10];

void setInitPoint(int i, int j, int &ir, int &ic)
{
	ir = i-(i%3==0 ? 2 : i%3-1);
	ic = j-(j%3==0 ? 2 : j%3-1);
}

int possibleNumbers(int r, int c, int *array)
{
	priority_queue<int, vector<int>, greater<int> > pq;
	for(int i=1; i<=9; i++)	array[i] = 0;
	int br, bc;
	setInitPoint(r, c, br, bc);
	
	for(int i=1; i<=9; i++)
	{
		array[ grid[r][i] ] = 1;
		array[ grid[i][c] ] = 1;
		array[ grid[br+((i-1)/3)][bc+((i-1)%3)] ] = 1;
	}
	
	for(int i=1; i<=9; i++) if(!array[i]) pq.push(i);
	int length = pq.size();
	for(int i=1; i<=length; i++) 
	{
		array[i] = pq.top();
		pq.pop();
	}
	return length;
}

bool solveSudoko()
{
	int mr=-1, mc=-1, ml= 20, l;
	int array[10];
	
	for(int i=1; i<=9; i++)
	for(int j=1; j<=9; j++)
	if(!grid[i][j])
	{
		l = possibleNumbers(i, j, array);
		if(l==0) return false;
		if(ml > l)
		{
			ml = l;
			mr = i;
			mc = j;
		}
	}
	
	if(mr==-1 && mc==-1) return true;
	ml = possibleNumbers(mr, mc, array);
	bool result;
	for(int i=1; i<=ml; i++)
	{
		grid[mr][mc] = array[i];
		result = solveSudoko();
		if(result==true) return true;
		grid[mr][mc] = 0;
	}
	
	return false;
}
		
	
	
int main()
{
	int T;
	scanf("%d", &T);
	for(int kase = 1; kase<=T; kase++)
	{
		puts("");
		char c;
		for(int i=1; i<=9; i++)
		for(int j=1; j<=9; j++)
		{
			scanf(" %c", &c);
			if(c=='.') grid[i][j] = 0;
			else if(c>='1' && c<='9') grid[i][j] = c-'0';
		}
		
		solveSudoko();
		printf("Case %d:\n", kase);
		for(int i=1; i<=9; i++)
		{
			for(int j=1; j<=9; j++)
				printf("%d", grid[i][j]);
			puts("");
		}
	}
	
	return 0;
}

