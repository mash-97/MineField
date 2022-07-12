#include <iostream>
#include <stdio.h>
#include <ratio>
#include <math.h>

using namespace std;
int da[10001][10];

void ratiolize(int *a, int *b)
{
	if(*a==1 || *b==1) return;
	int min = (*a>=*b) ? *b : *a;
	for(int i=min; i>=2; i--)
	{
		if(*a%i==0 && *b%i==0) 
		{
			*a = *a/i;
			*b = *b/i;
			ratiolize(a, b);
		}
	}
}

int op(int n, int p, int b)
{
	// moving the bit to the p position
	b = b<<p;
	int eb = b;
	for(int i=31; i>p; i--) eb = eb | (1<<i);
	for(int i=p-1; i>=0; i--) eb = eb | (1<<i);
	
	n &= eb;
	n |= b;
	return n;
}

int swapBits(int n, int p1, int p2)
{
	int b1 = (n>>p1) & 1;
	int b2 = (n>>p2) & 1;
	
	n = op(n, p1, b2);
	n = op(n, p2, b1);
	return n;
}

int swapBitsU(unsigned int n, unsigned int p1, unsigned int p2)
{
	unsigned int b1 = (n>>p1) & 1;
	unsigned int b2 = (n>>p2) & 1;
	
	unsigned int x = b1 ^ b2;
	x = (x<<p1)|(x<<p2);
	n = n^x;
	return n;
}
	
void showBits(int n)
{
	int bit_length = 32-__builtin_clz(n);
	for(int i=bit_length-1; i>=0; i--) printf("%d", (n>>i)&1);
	puts("\n");
}

int digits(int N)
{
	return ((int)log10((double)N))+1;
}

void init()
{
	//fda[10001][10];
	for(int i=1; i<=10000; i++)
	{
		int n = i;
		while(n)
		{
			da[i][n%10]++;
			n/=10;
		}
		for(int j=0; j<10; j++) da[i][j]+=da[i-1][j];
	}
}
int C2(int n, int N)
{
	int r = N % 10;
	int d = N / 10;
	
	int c=0;
	
	c += (r+1)*(d==n);
	c += 10*(N > (n*10+9));
	c += d;
	c += n<=r;
	
	c -= (11)*(n==0);
	return c;
}
int count = 0;
int C(int N, int n)
{
	count++;
	if(n==0) return 0;
	if(n<=9  && N<=n) return 1;
	int p10 = (int)pow(10, (int)log10(n));
	int r = n%p10;
	int d = n/p10;
	int result = d*C(N, p10-1)+C(N, r);
	result += (N==d) ? r+1 : (N<d ? p10 : 0);
	
	return result;
}

int p(int x, int y)
{
	return (int)pow((double)x, (double)y);
}
int C3(int N, int n)
{
	int count = 0;
	int d = digits(n);
	int i = 1;
	
	while(n/p(10, i))
	{
		
		count += ((n / p(10, i)) * p(10, i-1)) + ((n % p(10, i)) >= N*p(10, i-1)) * p(10, i-1);
		printf("i: %d, count: %d\n", i, count);
		i++;
	}
	count = count+(n % p(10, d-1))+1;
	printf("count: %d\n", count);
	return count;
}

int CC(int digit, int number)
{
	int total_digits = digits(number);
	int count = 0;
	
	int i = 1;
	int pp = 10;
	int p  = 1;
	while(i<=total_digits)
	{		
		count += (number / pp) * p;
	
		int nmp = (number % pp);
		
		if( nmp >= digit * p && nmp <= digit * p+ (p-1))
			count += (number % p)+1;
			
		else if(nmp > (digit*p + (p-1)))
		{
			count += p;
		}
		i+=1;
		p *= 10;
		pp *= 10;
	}
	return count;
}
			

int main()
{
	//printf("%d\n", CC(0, 20));
	init();
	int correct_count = 0;
	int incorrect_count = 0;
	int n = 10000;
	for(int i=1; i<=n; i++)
	for(int j=1; j<=9; j++)
	{
		if(da[i][j]!=CC(j, i)) incorrect_count++;
		if(da[i][j]==CC(j, i)) correct_count++;
	}
	printf("Incorrect Compare: %d\n", incorrect_count);
	printf("Correct Compare: %d\n", correct_count);
	if(correct_count == n*10 && incorrect_count==0) printf("\n\n\n-----Stimulation Successfull------\n");
	else printf("!Stimulation Unsuccessfull\n\n");
	//main();
	return 0;
}
