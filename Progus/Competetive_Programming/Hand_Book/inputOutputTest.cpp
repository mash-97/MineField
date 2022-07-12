#include <bits/stdc++.h>
using namespace std;

int main()
{
	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int n;
	scanf("%d", &n);
	int array[n];
	for(int i=0; i<n; i++) scanf("%d", &array[i]);
	
	int sum = 0;
	for(int i=0; i<n; i++) sum+=array[i];
	
	printf("%d\n", sum);
	
	
	
	return 0;
}
