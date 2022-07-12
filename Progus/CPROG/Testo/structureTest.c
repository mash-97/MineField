#include <stdio.h>
const int g = 100;
typedef struct S
{
	int G;
	int array[g];
} S;


int main()
{
	printf("g: "); scanf("%d", &g);
	S s;
	s.G = 1;
	s.array[0] = 5;
	
	printf("G: %d, array[0]: %d\n", s.G, s.array[0]);
	
	return 0;
}
