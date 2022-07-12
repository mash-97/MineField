#include <iostream>
#include <stdio.h>
#include <stack>

using namespace std;

void nearestSmallerElement(int length, int array[])
{
	stack<int> stack;
	for(int i=0; i<length; i++)
	{
		if(stack.empty()) 
			printf("%d: NULL\n", array[i]);
		else
		{
			while(!stack.empty() && stack.top() >= array[i]) 
				stack.pop();
			printf("%d: %d\n", array[i], stack.top());
		}
		stack.push(array[i]);
	}
}


int main()
{
	int n;
	scanf("%d", &n);
	int array[n];
	for(int i=0; i<n; i++) 
		scanf("%d", &array[i]);
	
	nearestSmallerElement(n, array);
	return 0;
}
