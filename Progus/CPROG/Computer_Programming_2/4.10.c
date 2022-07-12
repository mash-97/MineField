#include <stdio.h>
void A();
void B();
void C();

void C()
{
	static int count = 1;
	if(count>5) return;
	printf("In C: count = %d\n", count++);
	A();
}

void B()
{
	static int count = 1;
	if(count>5) return;
	printf("In B: count = %d\n", count++);
	C();
}

void A()
{
	static int count = 1;
	if(count>5) return;
	printf("In A: count = %d\n", count++);
	B();
}
void recurse()
{
	static int count = 1;
	if(count>5) return;
	printf("%d\n", count++);
	
	recurse();
}

int main()
{
	//recurse();
	A();
	return 0;
}
