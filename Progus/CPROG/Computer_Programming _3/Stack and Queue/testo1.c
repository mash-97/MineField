#include <stdio.h>


void homePage(void)
{
	//clear();
	printf("              Home            \n");
	printf("This is home page.\n");
}

void *returnFunct(void (*funct)(void))
{
	void * f;
	
	f = funct;
	
	return f;
}

int main()
{
	void (*p)(void);
	//p = returnFunct(&homePage);
	//p();
	p = homePage;
	p();
	return 0;
}
