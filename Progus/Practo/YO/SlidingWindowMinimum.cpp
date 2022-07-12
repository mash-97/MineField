#include <iostream>
#include <stdio.h>
#include <map>
#include <queue>
using namespace std;

void slidingWindowMinimum(int length, int *array, int window_size)
{
	deque<pair<int,int>> dq;
	
	for(int ws=1, we=0; we<length; we++, ws++)
	{
		if(we < window_size)	
			ws-=1;
		
		if(!dq.empty() && dq.front().first < ws)
			dq.pop_front();
		
		while(!dq.empty() && dq.back().second >= array[we])
			dq.pop_back();
		
		dq.push_back({we, array[we]});
		
		if(we>=window_size-1)
			printf("%d: %d\n", we, dq.front().second);
	}
}

int main()
{
	int n, w;
	scanf("%d%d", &n, &w);
	int array[n];
	for(int i=0; i<n; i++) 
		scanf("%d", &array[i]);
	
	slidingWindowMinimum(n, array, w);
	
	return 0;
}
