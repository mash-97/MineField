#include <iostream>
#include <cstdio>
#include <limits>

using namespace std;

template <class Type>
Type inf()
{
	return numeric_limits<Type>::max();
}

void display_array(int * array, int length)
{
	for(int i=0; i<length; i++)
		cout<<array[i]<<" \n"[i==length-1];
}

int f(int x, int *coins, int total_coins, int *array)
{
	if(x<0) return inf<int>()-1;
	if(x==0) return 0;
	if(array[x]) return array[x];
	else
	{
		int u = inf<int>();
		for(int i=0; i<total_coins; i++)
			u = min(u, f(x-coins[i], coins, total_coins, array)+1);
		array[x] = u;
	}

	return array[x];
}

int main()
{
	//for(int i=1; i<100; i++) cout<<inf<int>()<<endl;
	int total;
	cin>>total;
	int coins[total];
	
	for(auto &x: coins) cin>>x;
	
	int x;
	while(cin>>x)
	{
		int array[x+1];
		for(int i=0; i<x+1; i++) array[i] = 0;
		printf("F(%d): %d\n", x, f(x, coins, total, array));
	}
	return 0;
}
	
