#include <stdio.h>

long long int static_range_sum_v2(int a, int b, int size, long long int *sum_array) {
	if(a==0) return sum_array[b];
	return sum_array[b]-sum_array[a-1];
}

long long int static_range_sum_v1(int a, int b, int size, long long int array_sum, int *array) {
	int rab = (a-0)+(size-b-1);
	long long int range_sum = 0;
	if((b-a+1) < rab) {
		for(int i=a; i<=b; i++) 
			range_sum += array[i];
	}
	else {
		long long int asum = 0, bsum = 0;
		for(int i=0; i<=a-1; i++) 
			asum += array[i];
		for(int i=b+1; i<size; i++)
			bsum += array[i];
		range_sum = array_sum - (asum+bsum);
	}
	return range_sum;
}
int main(){
	int n, q;
	scanf("%d %d", &n, &q);
	
	int array[n];
	for(int i=0; i<n; i++)
		scanf("%d", &array[i]);
	
	long long int array_sum[n];
	array_sum[0] = array[0];
	for(int i=1; i<n; i++)
		array_sum[i] = array_sum[i-1]+array[i];
	
	while(q--) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%lld\n", static_range_sum_v2(a-1, b-1, n, array_sum));
	}
	return 0;
}
