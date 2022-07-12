#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node * next;
} Node;

Node * createNode(int data, Node *next)
{
	Node * new_node = (Node *) malloc(sizeof(Node));
	
	new_node->data = data;
	new_node->next = next;
	
	return new_node;
}

Node * prepend(int data, Node *head)
{
	Node * new_node = createNode(data, head);
	
	return new_node;
}

Node *append(int data, Node *head)
{
	Node * new_node = createNode(data, NULL);
	if(head==NULL) return new_node;
	
	Node * current_node = head;
	while(current_node->next != NULL) current_node = current_node->next;
	
	current_node->next = new_node;
	
	return head;
}

void displayLinkedList(Node *head)
{
	Node *current_node = head;
	
	while(current_node != NULL)
	{
		printf("%d ", current_node->data);
		current_node = current_node->next;
	}
	puts(".");
}

Node * removeNode(Node *head, Node *node)
{
	if(node == NULL) return head;
	if(node == head)
	{ 
		head = node->next;			// head = head-> next;
		
		// freeing memory for node
		free(node);
		
		return head;
	}
	
	Node * current_node = head;
	
	while(current_node != NULL)
	{
		if(current_node -> next == node) break;
		current_node = current_node -> next;
	}
	
	if(current_node == NULL) return head;
	
	current_node->next = node->next;
	
	free(node);
	
	return head;
}


int main()
{
	Node *n1, *head, *n2 = NULL;
	
	n1 = createNode(10, NULL);
	
	head = n1;
	displayLinkedList(head);
	
	head = prepend(20, head);
	displayLinkedList(head);
	
	head = append(30, head);
	displayLinkedList(head);
	
	head = removeNode(head, n1);
	displayLinkedList(head);
	
	n2 = head;
	head = removeNode(head, n2);
	displayLinkedList(head);
	
	n2 = head;
	head = removeNode(head, n2);
	displayLinkedList(head);
	/*
	head = removeNode(head, head);
	displayLinkedList(head);
	*/
	return 0;
}
