//Header Files Declarations...
#include <stdio.h>
#include <math.h>

//Macro Declarations...
#define NOT_FOUND -1
#define UNKNOWN -101
#define SIZE_ROOT 1000000
#define SIZE_ALL 1000000000000

//Global Declarations...
int Primes[SIZE_ROOT];
int mark[SIZE_ROOT+2];
int prime_count;

//Functions...

//Function to find all the primes between 0 and SIZE_ROOT.
void initailize()
{
	int lim = sqrt(SIZE_ROOT);
	prime_count = 0;
	
	for(int i=0; i<=SIZE_ROOT; i++)mark[i] = 1;
	for(int i=0; i<=SIZE_ROOT; i+=2)mark[i] = 0;
	
	mark[0] = 0;
	mark[1] = 0;
	mark[2] = 1;
	Primes[prime_count++] = 2;
	
	for(int i=3; i<=lim; i+=2)
	{
		if(mark[i] == 1)
		{
			Primes[prime_count++] = i;
			for(int j = i*i; j<=SIZE_ROOT; j+=2*i)
			{
				mark[j] = 0;
			}
		}
	}
} 
	
//Binary Search.
int searchPosition(int lowl, int array[], int bowl, int number)
{
	int half = (lowl+bowl)/2;
	if(array[half]==number) return half;
	else if(half==bowl || half==lowl || lowl==bowl) return NOT_FOUND;
	else if(array[half]>number) return searchPosition(lowl, array, half, number);
	else if(array[half]<number) return searchPosition(half, array, bowl, number);
	else return UNKNOWN;
}

int main()
{
	//Initializations...
	initailize();
	printf("INITIALIZED\n");
	//Variables Declarations...
	int T;
	long long int N;
	int root;
	int is_prime;
	
	scanf("%d", &T);
	while(T--)
	{
		scanf("%lld", &N);
		root = sqrt(N*1.0);
		is_prime = 1;
		if(N<=SIZE_ROOT && mark[N]==0) is_prime = 0;
		else
		{
			for(int i=0; Primes[i] <= root; i++)
			{
				if(N % Primes[i] == 0)
				{
					is_prime = 0;
					break;
				}
			}
		}
		
		
		if(is_prime == 1) printf("%lld is a prime\n", N);
		else printf("%lld is not prime.\n", N);
	}
	
	return 0;
}

	
