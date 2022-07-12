#include <stdio.h>

void function_1()
{
	int a=10;
	static int b=10;
	
	a += 10;
	b += 10;
	printf("function_1::\n");
	printf("a = %d\n", a);
	printf("static b = %d\n", b);
}

void function_2()
{
	int a=5;
	static int b=5;
	
	a += 10;
	b += 10;
	printf("function_2::\n");
	printf("a = %d\n", a);
	printf("static b = %d\n", b);
}

int main()
{
	function_1();
	function_1();
	function_2();
	function_1();
	function_2();
	
	return 0;
}
