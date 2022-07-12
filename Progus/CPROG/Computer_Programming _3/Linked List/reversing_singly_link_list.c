#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node Node;
struct Node
{
	int data;
	Node *next;
};

Node *create_node(int data)
{
	Node *new_node = (Node *) malloc(sizeof(Node));
	
	if(new_node==NULL) 
	{
		fprintf(stderr, "Failed to allocate memory for Node\n");
		exit(1);
	}
	
	new_node->data = data;
	new_node->next = NULL;
	
	return new_node;
}

Node *prepend(Node *root, Node *new_node)
{
	if(root == NULL) return new_node;
	if(new_node == NULL) return root;
	
	new_node->next = root;
	
	return new_node;
}

Node *append(Node *root, Node *new_node)
{
	if(root == NULL) return new_node;
	if(new_node == NULL) return root;
	
	Node * current_node = root;
	while(current_node->next != NULL) current_node = current_node->next;
	current_node->next = new_node;
	return root;
}

Node *find_prev_node(Node *root, Node *node)
{
	if(root == node) return NULL;
	
	Node *current_node = root;
	while(current_node->next != NULL)
	{
		if( current_node->next == node) return current_node;
		current_node = current_node->next;
	}
	
	return NULL;
}
 
void display_list(Node *root)
{
	int total_size = 0;
	
	Node *current_node = root;
	while(current_node != NULL)
	{
		total_size += sizeof(current_node);
		printf("%d ", current_node->data);
		current_node = current_node->next;
	}
	puts("");
	printf("Total Size: %d bytes\n", total_size);
}

Node *reverse_list(Node *root)
{
	if(root == NULL) return root;
	
	Node *previous_node, *current_node, *next_node;
	
	previous_node = NULL;
	current_node  = root;
	next_node     = root->next;
	
	while(current_node != NULL)
	{
		current_node->next = previous_node;
		previous_node = current_node;
		current_node = next_node;
		if(next_node != NULL) next_node = next_node->next;
	}
	
	return previous_node;
}


int main()
{
	Node *root = NULL;

	clock_t s = clock();
	
	for(int i=1; i<=10; i++) root = prepend(root, create_node(i));
	
	clock_t e = clock();
	
	//printf("Before Reversing: ");
	//display_list(root);
	
	root = reverse_list(root);
	printf("After Reversing: ");
	display_list(root);
	printf("Time: %.2lf\n", (double)(e-s)/CLOCKS_PER_SEC);
	puts("");
	puts("");
	
	Node *node = create_node(11);
	root = append(root, node);
	
	Node *anode = create_node(12);
	root = append(root, anode);
	
	Node *prev_node = find_prev_node(root, anode);
	if(prev_node == NULL)
	{
		if(root == node) printf("The node is root, so it's previous node is null\n");
		else printf("The node doesn't exist\n");
	}
	else
		printf("previous node is found: %d\n", prev_node->data);
		
	return 0;
}
	
