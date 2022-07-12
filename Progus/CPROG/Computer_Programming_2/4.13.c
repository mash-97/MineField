#include <stdio.h>
#include <string.h>
#define SIZE 500

int fib_array[50];
int f_calls = 0;
int flag = 0;

int fib(int n)
{
	++f_calls;

	int a, b;
	if(fib_array[n] == -1)
	{
		if(n==1 || n==2) return 1;
		//printf("#number = %d, fib_array[%d] = %d, fib_array[%d] = %d\n", n, n-1, fib_array[n-1], n-2, fib_array[n-2]);
		if(fib_array[n-1] == -1) fib_array[n-1] = a = fib(n-1);
		else a = fib_array[n-1];
		if(fib_array[n-2] == -1) fib_array[n-2] = b = fib(n-2);
		else b = fib_array[n-2];

		return a+b;
	}
	else return fib_array[n];
}

int main()
{
	if(flag==0)
	{ 
		flag = 1;
		for(int i=0; i<SIZE; i++)fib_array[i]=-1;
		fib_array[0] = 0;
		fib_array[1] = 1;
		fib_array[1] = 1;
	}

	f_calls = 0;
	
	int n;
	char s[3];
	
	scanf("%d", &n);
	
	if(n==1) strcpy(s, "st");
	else if(n==2) strcpy(s, "nd");
	else if(n==3) strcpy(s, "rd");
	else strcpy(s, "th");
	
	printf("%d%s fibonacci number is %d\n", n, s, fib(n));
	printf("Number of function calls: %d\n", f_calls);
	/*
	printf("----------------------------------------\n");
	for(int i=0; i<50; i++)printf("%d\t", fib_array[i]);*/
	main();
	return 0;
}
