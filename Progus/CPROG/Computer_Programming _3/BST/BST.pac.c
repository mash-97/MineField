#include <stdio.h>
#include <stdlib.h>

#define newl puts("")

typedef struct Node Node;
struct Node
{
	int data;
	
	Node * parent;
	Node * left;
	Node * right;
};

typedef struct Bst_Search_Returno Bst_Search_Returno;
struct Bst_Search_Returno
{
	int found;
	Node * self;
	Node *parent;
	Node *left;
	Node *right;
};

Node * createNode(int data)
{
	Node * new_node = (Node *) malloc(sizeof(Node));
	
	new_node->data = data;
	new_node->left = NULL;
	new_node->right = NULL;
	
	return new_node;
}


void add_left_child(Node *parent, Node *left_child)
{
	parent->left = left_child;
	left_child->parent = parent;
}

void add_right_child(Node *parent, Node *right_child)
{
	 parent->right = right_child;
	 right_child->parent = parent;
}

Node * bst_insert(Node *root, Node *node)
{
	if(root==NULL) return node;
	if(node==NULL) return root;
	
	Node *current_node, *parent_node;
	
	current_node = root;
	while(current_node)
	{
		parent_node = current_node;
		if(parent_node->data > node->data) current_node = parent_node->left;
		else if(parent_node->data < node->data) current_node = parent_node->right;
		else return root;
	}
	
	if(parent_node->data > node->data) add_left_child(parent_node, node);
	else add_right_child(parent_node, node);
	
	return root;
}


Node * search_bst_node(Node *root, Node *node)
{
	if(root && node)
	{
		if(root->data==node->data) return node;
		Node *current_node = root;
		while(current_node)
		{
			if(current_node->data > node->data) current_node = current_node->left;
			else if(current_node->data < node->data) current_node = current_node->right;
			else return node;
		}
	}
	return NULL;
}

Bst_Search_Returno searchBSTNode(Node *root, Node *node)
{
	Bst_Search_Returno returno;
	Node *current_node, *parent_node;
	
	returno.self = NULL;
	returno.found = 0;
	returno.parent = NULL;
	returno.left = NULL;
	returno.right = NULL;
	
	current_node = root;
	
	while(current_node)
	{
		parent_node = current_node;
		if(parent_node->data > node->data) current_node = parent_node->left;
		else if(parent_node->data < node->data) current_node = parent_node->right;
		else 
		{
			returno.found = 1;
			returno.self = node;
			returno.parent = parent_node;
			if(current_node->left) returno.left = current_node->left;
			if(current_node->right) returno.right = current_node->right;
			break;
		}
	}
	return returno;
}

void interactiveSearch(Node *root, Node *node)
{
	Bst_Search_Returno res = searchBSTNode(root, node);
	
	newl;
	if(res.found)
	{
		printf("The node with %d data is found.\n", res.self->data);
		if(res.self->parent!=NULL) printf("It's parent is %d (:%d)\n", res.parent->data, res.self->parent->data);
		if(res.left==NULL && res.right==NULL) printf("It's a leaf\n");
		if(res.left || res.right)
		{
			printf("It's also a parent of ");
			if(res.left) printf("left: %d ", res.left->data);
			if(res.right)
			{
				if(res.left) printf(" and right: %d", res.right->data);
				else printf("right: %d", res.right->data);
			}
			newl;
		}
	}
	else printf("The node with %d data is not found!!!.\n", node->data);
	newl;
}

/*
	 *								________10________
	 * 							   /                  \
	 *                         ___7___             ___15___
	 *                        /       \           /        \
	 *                      _5_        8        _13_       _17_
	 *                     /   \               /    \     /    \
	 *                    3     6             12    14   16    20
	 * 				     / 										 \
	 * 					2										  21
	 * 
*/
Node * create_bst()
{
	Node *root = createNode(10);
	int array[] = {7, 15, 5, 8, 13, 17, 3, 6, 12, 14, 16, 20, 2, 21};
	for(int i=0; i<14; i++) root = bst_insert(root, createNode(array[i]));
	return root;
}

void preDisplay(Node *root)
{
	if(root==NULL) return;
	printf("%d ", root->data);
	preDisplay(root->left);
	preDisplay(root->right);
}

void postDisplay(Node *root)
{
	if(root==NULL) return;
	postDisplay(root->left);
	postDisplay(root->right);
	printf("%d ", root->data);
}

void inDisplay(Node *root)
{
	if(root==NULL) return;
	inDisplay(root->left);
	printf("%d ", root->data);
	inDisplay(root->right);
}

Node * maximumNode(Node *root)
{
	Node * current_node;
	current_node = root;
	while(current_node->right) current_node = current_node->right;
	return current_node;
}

Node * minimumNode(Node *root)
{
	Node * current_node = root;
	while(current_node->left) current_node = current_node->left;
	return current_node;
}

int main()
{
	Node *root = create_bst();
	
	printf("Pre-display:\n");
	preDisplay(root);
	newl;
	
	printf("In-display:\n");
	inDisplay(root);
	newl;
	
	printf("Post-display:\n");
	postDisplay(root);
	newl;
	
	Node *node = createNode(15);
	Node *node_2 = createNode(20);
	Node *node_3 = search_bst_node(root, createNode(6));
	
	interactiveSearch(root, node);
	interactiveSearch(root, node_2);
	interactiveSearch(root, node_3);
	interactiveSearch(root, createNode(8));
	interactiveSearch(root, createNode(7));
	
	newl;
	newl;
	
	printf("The minimum data is %d in the node.\n\n", minimumNode(root)->data);
	printf("The maximum data is %d in the node.\n\n", maximumNode(root)->data);
	return 0;
}
