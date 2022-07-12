#include <iostream>
using namespace std;

int n;
int r1[20];
int r2[40];
int r3[40];
int count = 0;

void backtrack_the_queens(int r)
{
	if(r==n)
	{
		count++;
		return;
	}
	
	for(int c=0; c<n; c++)
	if(!r1[c] && !r2[r+c] && !r3[(n-1)+c-r])
	{
		r1[c] = r2[r+c] = r3[(n-1)+c-r] = 1;
		backtrack_the_queens(r+1);
		r1[c] = r2[r+c] = r3[(n-1)+c-r] = 0;
	}
}


int main()
{
	cin>>n;
	backtrack_the_queens(0);
	cout<<count<<endl;
	return 0;
}
	
