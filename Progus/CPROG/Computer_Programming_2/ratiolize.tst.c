#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define infinity -1

typedef struct
{
	int p;
	int q;
	double value;

} Rational;

int mainor(int a, int b)
{
	return ((a+b)-abs(a-b))/2;
}
int isPrime(int number)
{
	int root;
	if(number < 2 || number % 2 == 0) return 0;
	else if(number==2) return 1;
	else
	{
		root = sqrt(number);
		for(int i=3; i<=root; i+=2) if(number%i==0) return 0;
	}
	return 1;
}


int gcd(int a, int b)
{
	int temp;
	while(b!=0)
	{
		temp = b;
		b = a%b;
		a = temp;
	}
	return a;
}

int lcd(int a, int b)
{
	return (a*b)/gcd(a,b);
}

Rational ratiolize(int a, int b)
{
	
	int lim;
	Rational result;
	result.p = a;
	result.q = b;
	if(b==0)
	{
		//printf("1\n");
		result.p = a;
		result.q = 0;
		result.value = infinity*(0.9999999);
	}
	else if(a==0)
	{
		//printf("2\n");
		result.p = 0;
		result.q = b;
		result.value = 0.0;
	}
	else if(a%b==0)
	{
		//printf("3\n");
		result.p = result.value = (a*1.0/b);
		result.q = 1;
	}
	else if(b%a==0)
	{
		//printf("4\n");
		result.p = 1;
		result.q = b/a;
		result.value = 1.0/result.q;
	}
	/*
	else if(isPrime(a)==1 && isPrime(b)==1)
	{
		printf("5\n");
		result.p = a;
		result.q = b;
		result.value = (a*1.0)/b;
	}
	*/
	
	else
	{
		lim = (((a+b)-abs(a-b))/2)/2;
		result.value =( a*1.0)/b;
		
		for(int i=2; i<=lim; i++)
		{
			if(a%i==0 && b%i==0)
			{
				//printf("k: %d\n", i);
				result.p = a/i;
				result.q = b/i;
				
				result = ratiolize(result.p, result.q);
				
				result.value = (result.p*1.0)/result.q;
			}
		}
	}
	
	//printf("a = %d, b = %d\n", a, b);
	//printf("p = %d, q = %d\n", result.p, result.q);
	return(result);
}
	
int main()
{
	Rational r;
	int a, b;
	scanf("%d %d", &a, &b);
	r = ratiolize(a,b);
	printf("%d/%d\n\n", r.p, r.q);
	main();
	return 0;
}
