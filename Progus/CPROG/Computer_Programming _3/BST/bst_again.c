#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
struct Node
{
	int data;
	Node *parent;
	Node *left;
	Node *right;
};

Node *createNode(int data)
{
	Node *new_node = (Node *) malloc(sizeof(Node));
	if(new_node == NULL)
	{
		fprintf(stderr, "Error! could not allocate memroy for Node\n");
		exit(1);
	}
	new_node->data = data;
	new_node->parent = NULL;
	new_node->left = NULL;
	new_node->right = NULL;
	return new_node;
}

void add_left_child(Node *parent, Node *child)
{
	if(parent != NULL) parent->left  = child;
	if(child  != NULL) child->parent = parent;
}

void add_right_child(Node *parent, Node *child)
{
	if(parent != NULL) parent->right  = child;
	if(child != NULL)  child ->parent = parent;
}

Node *bst_insert(Node *root, Node *new_node)
{
	if(root == NULL) return new_node;
	Node *parent, *current_node;
	
	parent = NULL;
	current_node = root;
	
	while(current_node != NULL)
	{
		parent = current_node;
		if(current_node->data > new_node->data) current_node = current_node->left;
		else current_node = current_node->right;
	}
	
	if(parent->data > new_node->data) add_left_child(parent, new_node);
	else add_right_child(parent, new_node);
	
	return root;
}


Node *createBSTTree()
{
	Node *root = NULL;
	int array[] = {10, 5, 17, 3, 7, 12, 19, 1, 4, 13};
	
	for(int i=0; i<10; i++) root = bst_insert(root, createNode(array[i]));
	
	return root;
}

void traverse_in_order(Node *root)
{
	if(root == NULL) return;
	traverse_in_order(root->left);
	printf("%d ", root->data);
	traverse_in_order(root->right);
}

void traverse_post_order(Node *root)
{
	if(root == NULL) return;
	traverse_post_order(root->left);
	traverse_post_order(root->right);
	printf("%d ", root->data);
}

Node * minimum_node(Node *root)
{
	Node *current_node = root;
	while(current_node->left!=NULL) current_node = current_node ->left;
	return current_node;
}


Node *bst_transplant(Node *root, Node *current_node, Node *new_node)
{
	if(root == NULL || current_node == NULL) return root;
	
	if(root == current_node) return new_node;
	else if(current_node == current_node->parent->left) add_left_child(current_node->parent, new_node);
	else add_right_child(current_node->parent, new_node);
	
	return root;
}

Node *bst_delete(Node *root, Node *node)
{
	if(root == NULL || node == NULL) return root;
	
	if(node->left == NULL) root = bst_transplant(root, node, node->right);
	else if(node->right == NULL) root = bst_transplant(root, node, node->left);
	else 
	{
		Node *smallest_node = minimum_node(node->right);
		
		if(smallest_node->parent != node)
		{
			root = bst_transplant(root, smallest_node, smallest_node->right);
			add_right_child(smallest_node, node->right);
		}
		
		root = bst_transplant(root, node, smallest_node);
		add_left_child(smallest_node, node->left);
	}
	
	free(node);
	return root;
}

Node *bst_search(Node *root, int data)
{
	Node *current_node = root;
	while(current_node != NULL)
	{
		if(current_node->data == data) return current_node;
		else if(current_node->data > data) current_node = current_node->left;
		else current_node = current_node->right;
	}
	return current_node;
}


int main()
{
	Node *root = createBSTTree();
	Node *node;
	
	printf("BST: \n");
	traverse_in_order(root);
	printf("\n");
	
	node = bst_search(root, 1);
	
	if(node != NULL)
	{
		printf("Will delete %d\n", node->data);
		root = bst_delete(root, node);
		
		printf("BST:\n");
		traverse_in_order(root);
		printf("\n");
	}
	else
	{
		printf("Node not found!\n");
	}
	
	node = bst_search(root, 5);
	if(node != NULL) 
	{
		printf("Will delete %d\n", node->data);
		root = bst_delete(root, node);
		printf("BST:\n");
		traverse_in_order(root);
		printf("\n");
	}
	else printf("Node not found!\n");
	
	node = bst_search(root, 10);
	if(node != NULL)
	{
		printf("Will delete %d\n", node->data);
		root = bst_delete(root, node);
		printf("BST:\n");
		traverse_in_order(root);
		printf("\n");
	}
	else printf("Node not found!\n");
	
	
	
	for(int i=1; i<=11; i++)
	{
		if(root) printf("Will delete %d\n", root->data);
		root = bst_delete(root, root);
		printf("BST:\n");
		traverse_in_order(root);
		puts("\n");
	}
	
	return 0;
}
