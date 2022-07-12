#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node *next;
} Node;


Node * createNode(int data, void * next)
{
	Node *new_node = (Node *) malloc(sizeof(Node));
	
	if(new_node == NULL) 
	{
		printf("Error! Could not create a new node!\n");
		exit(1);
	}
	
	new_node->data = data;
	new_node->next = next;
	
	return new_node;
}

int main()
{
	Node *new_node;
	Node *new_node1 = createNode(6, NULL);
	new_node = createNode(5, new_node1);
	
	printf("data: %d, %d\n", new_node->data, new_node->next->data);
	
	return 0;
}
