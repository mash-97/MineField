#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;

struct node
{
	int data;
	struct node * next;
};

Node *createNode(int item, Node *next)
{
	Node *aNode = (Node*) malloc(sizeof(Node));
	aNode->data = item;
	aNode->next = next;
	
	return aNode;
}

Node *prepend(int item, Node *head)
{
	Node *aNode = createNode(item, head);
	
	return aNode;
}

void displayNodesData(Node *a_node)
{
	if(a_node==NULL) printf("This node is NULL\n");
	else printf("node->data : %d\n", a_node->data);
}

int main()
{
	Node *n1, *head;
	
	n1 = createNode(10, NULL);
	n1 = createNode(20, n1);
	head = n1;
	
	head = prepend(30, head);
	
	displayNodesData(head);
	displayNodesData(head->next);
	displayNodesData(head->next->next);
	displayNodesData(head->next->next->next);
	
	return 0;
}

