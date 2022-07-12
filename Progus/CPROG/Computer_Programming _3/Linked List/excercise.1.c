#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
struct node
{
	int data;
	struct node *next;
};

// Head Node keeps the node above all of the nodes.
// Function to create a node, as takes a item to keep into data and a next Node to point next to this new node, returns new node.
Node *createNode(int item, Node *next)
{
	Node *new_node = (Node *) malloc(sizeof(Node));
	
	new_node->data = item;
	new_node->next = next;
	
	return new_node;
}

// Function to create a node at the head, as takes a item to keep into data and a head Node to point next to the newly created 
// node, returns the newly created node as head.
Node *prepend(int item, Node *head)
{
	Node *new_node = createNode(item, head);
	
	return new_node;
}

// Function to create a node at the last of the linked list, it takes a item and a head Node to locate the last position of the
// Linked List, returns the head.
Node *append(int item, Node *head)
{
	Node *new_node = createNode(item, NULL);
	
	if(head==NULL) return new_node;								// new_node is the first node of the list as there's no node yet.
	
	// Locating the last node.
	Node *current_node = head;
	
	while(current_node->next!=NULL) current_node = current_node->next;
	
	current_node->next = new_node;
	
	return head;
}

void viewLinkedList(Node *head)
{
	Node *current_node = head;
	
	while(current_node!=NULL)
	{
		printf("%d ", current_node->data);
		current_node = current_node->next;
	}
	puts("");
}

int count(Node *head)
{
	int count = 0;
	Node *current_node = head;
	
	while(current_node!=NULL) 
	{
		++count;
		current_node = current_node->next;
	}
	return count;
}

Node *search(int item, Node *head)
{
	Node *current_node = head;
	
	while(current_node!=NULL) 
	{
		if(current_node->data==item) return current_node;
		current_node = current_node->next;
	}
	
	return NULL;
}

Node *createLinkedListFrom(int array[], int length)
{
	if(length==0) return NULL;
	
	Node *new_node = createNode(array[length-1], NULL);
	for(int i=length-2; i>=0; i--) new_node = prepend(array[i], new_node);
	return new_node;
}

void displayNodesData(Node *a_node)
{
	if(a_node==NULL) printf("node is null!\n");
	else printf("%d\n", a_node->data);
}

int main()
{
	int length = 10;
	int array[] = {1,2,3,4,5,6,7,8,9,10};
	
	Node *head = createLinkedListFrom(array, length);
	viewLinkedList(head);
	
	printf("Total nodes: %d\n", count(head));
	printf("Enter a number: ");
	int number; scanf("%d", &number);
	
	Node *found_node = search(number, head);
	if(found_node==NULL) printf("The number is not found in the list!\n");
	else printf("The number %d is found in the list, it's next number is ", found_node->data);
	displayNodesData(found_node->next);
	
	return 0;
}
	
