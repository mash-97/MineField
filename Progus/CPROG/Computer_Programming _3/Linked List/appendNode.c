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

Node *append(int item, Node *head)
{
	Node *new_node = createNode(item, NULL);
	
	if(head==NULL) return new_node;
	
	Node *current_node = head;
	
	while(current_node->next !=NULL) current_node = current_node->next;
	
	current_node->next = new_node;
	
	return head;
}

void displayNodesData(Node *a_node)
{
	if(a_node==NULL) printf("This node is NULL\n");
	else printf("node->data : %d\n", a_node->data);
}

int main()
{	
	Node *head = append(10, NULL);
	
	for(int i=20; i<=100; i+=10) head = append(i, head);
	
	
	Node *current_node = head;
	while(current_node != NULL)
	{
		displayNodesData(current_node);
		current_node = current_node->next;
	}
	return 0;
}
