#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int count = 0;
int n;
int calls = 0;

int array[20][20];

bool check(int x)
{
	return (x>=0 && x<n) ? 1 : 0;
}

bool empty(int r, int c)
{
	return !array[r][c];
}

bool optimize4(int r, int c)
{
	if((r==0 || r==n-1) && ((check(c+1) && empty(r, c+1)) && (check(c-1) && empty(r, c-1)))) return 1;
	if((c==0 || c==n-1) && ((check(r+1) && empty(r+1, c)) && (check(r-1) && empty(r-1, c)))) return 1;
	return 0;
}


void count_paths(int r, int c, int i)
{
	calls++;
	if(r==n-1 && c==n-1)
	{
		if(i == n*n)
		{
			//~ system("clear");
			//~ cout<<"count: "<<count<<"\n";
			++count;
		}
		return;
	}
	if(i==(n*n)) return;
	if(optimize4(r, c)) return;
	
	array[r][c] = 1;
	
	if(check(r+1) && !array[r+1][c]) 
		count_paths(r+1, c, i+1);
	
	if(check(r-1) && !array[r-1][c])
		count_paths(r-1, c, i+1);

	if(check(c+1) && !array[r][c+1] ) 
		count_paths(r, c+1, i+1);
	
	if(check(c-1) && !array[r][c-1])
		count_paths(r, c-1, i+1);

	array[r][c] = 0;
}

int main()
{
	calls = 0;
	cin >> n;
	clock_t s = clock();
	count_paths(0, 0, 1);
	clock_t e = clock();
	
	cout<<count<<endl;
	cout<<"execution time: "<<((double)(e-s)/CLOCKS_PER_SEC)<<endl;
	cout<<"Total calls: "<<calls<<endl;
	return 0;
}
	
	
