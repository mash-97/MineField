#include <stdio.h>
#include <stdlib.h>

#define newl puts("")

typedef struct Node Node;

struct Node
{
	int data;
	Node *parent;
	Node *left;
	Node *right;
};

Node * createNode(int data)
{
	Node * new_node = (Node *) malloc(sizeof(Node));
	
	new_node->data = data;
	new_node->parent = NULL;
	new_node->left = NULL;
	new_node->right = NULL;
	
	return new_node;
}

void add_to_left(Node *parent, Node *child)
{
	parent->left = child;
	child->parent = parent;
}

void add_to_right(Node *parent, Node *child)
{
	parent->right = child;
	child->parent = parent;
}

Node * bst_insert(Node *root, Node *node)
{
	if(node==NULL) return root;
	if(root==NULL) return node;
	
	Node *parent_node, *current_node;
	
	current_node = root;
	while(current_node!=NULL)
	{
		parent_node = current_node;
		if(node->data < current_node->data) current_node = current_node->left;
		else if(node->data > current_node->data) current_node = current_node->right;
		else return root;
	}
	
	if(node->data < parent_node->data) add_to_left(parent_node, node);
	else add_to_right(parent_node, node);
	
	return root;
}


Node *create_bst()
{
	Node *root, *node;
	
	int array[] = {7,11, 5, 21, 9, 16, 3, 6, 8, 23, 12, 20};
	
	root = createNode(10);
	
	for(int i=0; i<12; i++)
	{
		node = createNode(array[i]);
		root = bst_insert(root, node);
	}
	
	return root;
}

void display_in_pre_order(Node *root)
{
	if(root==NULL) return;
	
	printf("%d ", root->data);
	
	display_in_pre_order(root->left);
	display_in_pre_order(root->right);
}

void display_in_post_order(Node *root)
{
	if(root==NULL) return;
	
	display_in_post_order(root->left);
	display_in_post_order(root->right);
	
	printf("%d ", root->data);
}

void display_in_in_order(Node *root)
{
	if(root==NULL) return;
	
	display_in_in_order(root->left);
	
	printf("%d ", root->data);
	
	display_in_in_order(root->right);
}

int steps = 0;
Node *bst_search(Node *root, int data)
{
	while(root!=NULL)
	{
		++steps;
		if(root->data == data) return root;
		else if(root->data > data) root = root->left;
		else if(root->data < data) root = root->right;
	}
	
	return root;
}

int main()
{
	Node *root = create_bst();
	
	printf("Displaying in pre-order traverse: ");
	display_in_pre_order(root);
	newl;
	
	printf("Displaying in post-order traverse: ");
	display_in_post_order(root);
	newl;
	
	printf("Displaying in in-order traverse: ");
	display_in_in_order(root);
	newl;
	
	newl;
	newl;
	newl;
	printf("BST search: \n");
	Node *node = bst_search(root, 7);
	
	if(node)	printf("Node is found: %d\n", node->data);
	else printf("Node is not found: ERROR_SEARCH\n");
	printf("Total steps: %d\n", steps);
	newl;
	newl;
	
	steps = 0;
	node = bst_search(root, 1);
	if(node)	printf("Node is found: %d\n", node->data);
	else printf("Node is not found: ERROR_SEARCH\n");
	printf("Total steps: %d\n", steps);
	
	newl;
	newl;
	steps = 0;
	node = bst_search(root, 4);
	if(node)	printf("Node is found: %d\n", node->data);
	else printf("Node is not found: ERROR_SEARCH\n");
	printf("Total steps: %d\n", steps);
	
	newl;
	newl;
	steps = 0;
	node = bst_search(root, 8);
	if(node)	printf("Node is found: %d\n", node->data);
	else printf("Node is not found: ERROR_SEARCH\n");
	printf("Total steps: %d\n", steps);
	return 0;
}
