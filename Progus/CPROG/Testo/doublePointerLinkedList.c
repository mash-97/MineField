#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
struct Node
{
	int data;
	Node *next;
};

Node *createNode(int data)
{
	Node *new_node = (Node *) malloc(sizeof(Node));
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}

Node *addToTheList(Node *root, Node *node)
{
	if(root==NULL) return node;
	Node *current_node = root;
	while(current_node->next)	current_node = current_node->next;
	current_node->next = node;
	return root;
}

void deleteDataFrom(Node *root, int data)
{
	if(root->data==data) root = NULL;
	
	Node *current_node = root;
	while(current_node && current_node->next->data != data) current_node = current_node->next;
	if(current_node) current_node->next = current_node->next->next;
}

void display(Node *root)
{
	Node *current_node = root;
	while(current_node->next) 
	{
		printf("%d ", current_node->data);
		current_node = current_node->next;
	}
	printf("%d\n", current_node->data);
}


int main()
{
	Node *root = createNode(1);
	Node *s = createNode(2);
	Node *t = createNode(3);
	Node *f = createNode(4);
	Node *fi = createNode(5);

	root = addToTheList(root, s);
	root = addToTheList(root, t);
	root = addToTheList(root, f);
	root = addToTheList(root, fi);

	display(root);

	getchar();
	deleteDataFrom(root, 2);
	deleteDataFrom(root, 3);
	getchar();
	display(root);
	
	return 0;
}
