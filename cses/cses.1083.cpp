#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	long long int sum = 0;
	int n, inp;
	scanf("%d", &n);
	
	for(int i=0; i<n-1; i++)
	{
		scanf("%d", &inp);
		sum += inp;
	}
	long long int esum = (long long int)((double)(n+1)*(double)((n*1.0)/2));
	printf("%lld\n", esum-sum);
	
	return 0;
}
