#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;

struct node
{
	int data;
	struct node *next;
};



Node *createNode(int item, Node *next)
{
	Node *aNode = (Node *) malloc(sizeof(Node));
	
	aNode->data = item;
	aNode->next = next;
	
	return aNode;
}


int main()
{
	Node *aNode = createNode(33, NULL);
	
	printf("aNode->data : %d\n", aNode->data);
	
	return 0;
}
