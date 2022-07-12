#include <stdio.h>

typedef struct Names
{
	char *first_name;
	char *last_name;
}Names, One;

struct Ref
{
	int d;
	int e;
}Two, three;

One head;
One tail;

int main()
{
	Names one;
	head.first_name = "Siddique";
	tail.last_name = "Rahman";
	one.first_name = "Mashiur";
	one.last_name = "Rahman";
	printf("%s %s\n", one.first_name, one.last_name);
	printf("%s %s\n", head.first_name, tail.last_name);
	printf("\n\n");
	Two.d = 11;
	Two.e = 12;
	three.d = 22;
	three.e = 21;
	printf("Two: d = %d, e = %d\n", Two.d, Two.e);
	printf("Three: d = %d, e = %d\n", three.d, three.e);
	return 0;
}
