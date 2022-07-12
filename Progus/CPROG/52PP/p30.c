#include <stdio.h>
#include <math.h>
int isPerfectNumber(unsigned long long int number)
{
	if(number==1)return 0;
	double n = number;
	unsigned long long int sum = 1;
	double root = sqrt(n);
	unsigned long long i;
	if(number%2==0)
	{
		for(i=2; i<=root && sum<=number; i++)if(number%i==0)sum+=i+(number/i);
	}
	else
	{
		for(i=3; i<=root && sum <= number; i+=2)
		if(number%i==0 ) sum+=i+(number/i);
	}
	
	if(sum!=number)return 0;
	return 1;
}

int main()
{
	int T;
	long long unsigned number;
	
	scanf("%d", &T);
	while(T--)
	{
		scanf("%llu", &number);
		if(isPerfectNumber(number)==1)printf("YES, %llu is a perfect number!\n", number);
		else printf("NO, %llu is not a perfect number!\n", number);
	}
	return 0;
}
