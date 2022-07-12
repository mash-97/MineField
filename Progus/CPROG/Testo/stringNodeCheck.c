#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
struct Node
{
	char *name;
	Node *next;
};


int main()
{
	Node * a = (Node *) malloc(sizeof(Node));
	char *name = "heall";
	a->name = name;
	printf("%s\n", a->name);
	
	return 0;
}
