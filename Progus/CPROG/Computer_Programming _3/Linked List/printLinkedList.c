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
	Node *new_node = (Node *) malloc(sizeof(Node));
	
	new_node->data = item;
	new_node->next = next;
	
	return new_node;
}

Node *prepend(int item, Node *head)
{
	Node *new_node = createNode(item, head);
	return new_node;
}

Node *append(int item, Node *head)
{
	Node *new_node = createNode(item, NULL);
	
	if(head==NULL) return new_node;
	
	Node *current_node = head;
	
	while(current_node->next != NULL) current_node = current_node->next;
	
	current_node->next = new_node;
	
	return head;
}

void print_linked_list(Node *head)
{
	if(head==NULL){ printf("The node is NULL!\n"); return;}
	
	Node *current_node = head;
	while(current_node != NULL)
	{
		printf("%d ", current_node->data);
		current_node = current_node->next;
	}
	puts("");
}

int main()
{
	Node *n1, *head;
	
	n1 = createNode(10, NULL);
	
	head = n1;
	head = append(20, head);
	head = append(30, head);
	head = append(40, head);
	head = append(50, head);
	head = prepend(60, head);
	head = prepend(70, head);
	head = append(80, head);
	
	print_linked_list(head);
	return 0;
}
