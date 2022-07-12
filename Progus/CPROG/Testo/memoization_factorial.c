#include <stdio.h>
#include <time.h>

long long unsigned factorials[21];

long long unsigned facto(int n)
{
	if(n==0) return 1;
	
	if(factorials[n]) return factorials[n];
	else return (factorials[n] = n*facto(n-1));
}
	
void disp(long long unsigned *a, int l)
{
	for(int i=0; i<l; i++) printf("%d!  =>  %llu\n", i, factorials[i]);
	puts("");
}

int main()
{
	factorials[0] = 1;
	
	printf("Before calling: \n"); 
	disp(factorials, 21);
	
	clock_t s = clock();
	printf("15! => %llu\n", facto(15));
	clock_t e = clock();
	
	printf("Ex: %.6lf\n", (double)(e-s)/CLOCKS_PER_SEC);
	printf("After first calling: \n"); 
	disp(factorials, 21);
	
	s = clock();
	printf("19! => %llu\n", facto(19));	
	e = clock();
	
	printf("Ex: %.6lf\n", (double)(e-s)/CLOCKS_PER_SEC);
	
	return 0;
}
