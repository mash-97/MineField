#include <stdio.h>

struct s
{
	char ch;
	int n;
	char str[16];
	int m;
	char d[20];
} sv;

union u
{
	char ch;
	int n;
	char str[16];
} uv;

int main()
{
	int struct_size, union_size;
	
	struct_size = sizeof(sv);
	union_size = sizeof(uv);
	
	printf("Size of int : %ld bytes\n", sizeof(int));
	printf("Size of 16 chars : %ld bytes\n\n", sizeof(char)*16);
	
	printf("Structure variable took %d bytes\n", struct_size);
	printf("Union variable took %d bytes\n", union_size);
	
	return 0;
}
