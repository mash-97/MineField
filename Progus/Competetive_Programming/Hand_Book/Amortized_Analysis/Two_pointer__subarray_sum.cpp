#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;

deque<int> subArraySum(int x, int n, int *array)
{
	int *l = &array[0];
	int *r = l;
	int sum = *l;
	
	int count = 1;
	deque<int> subarray;
	subarray.push_back(array[0]);
	
	while(!(l==array+n-1 && r==array+n-1))
	{
		if(sum==x) return subarray;
		while(r+1 < array+n && sum+*(r+1) <=x) 
		{
			if(sum==x) return subarray;
			subarray.push_back(*(++r));
			count++;
		}
		
		++l;
		subarray.pop_front();
		count--;
	}
	return subarray;
}

int main()
{
	int n, x;
	scanf("%d", &n);
	int *array = new int[n];
	for(int *i=array; i<array+n; i++)
		scanf("%d", i);
	
	while(~scanf("%d", &x))
	{
		deque<int> r = subArraySum(x, n, array);
		printf("subarray size: %d\n", (int)r.size());
		for(auto i: r)
			printf("%d ", i);
		puts("");
	}
	return 0;
}
