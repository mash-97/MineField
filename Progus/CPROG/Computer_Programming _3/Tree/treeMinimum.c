#include <stdio.h>
#include <stdlib.h>

#define newl puts("")

typedef struct Node Node;
struct Node 
{
	int data;
	Node *left;
	Node *right;
};

Node * createNode(int data)
{
	Node *new_node = (Node *) malloc(sizeof(Node));
	
	new_node->data = data;
	new_node->left = NULL;
	new_node->right = NULL;

	return new_node;
}

void add_to_left(Node *parent, Node *child)
{
	parent->left = child;
}
void add_to_right(Node *parent, Node *child)
{
	parent->right = child;
}
void add_child(Node *parent, Node *left_child, Node *right_child)
{
	parent->left = left_child;
	parent->right = right_child;
}

Node * createTheTree()
{
	Node *two = createNode(2);
	Node *seven = createNode(7);
	Node *nine = createNode(9);
	Node *six = createNode(6);
	Node *one = createNode(1);
	Node *eight = createNode(8);
	Node *three = createNode(3);
	Node *four = createNode(4);
	Node *five = createNode(5);
	Node *ten = createNode(10);
	
	add_child(seven, one, six);
	add_child(two, seven, nine);
	add_child(eight, three, four);
	add_to_right(nine, eight);
	add_child(six, five, ten);
	
	return two;
}

void preOrderTraverse(Node *root)
{
	if(root==NULL) return;
	printf("%d ", root->data);
	preOrderTraverse(root->left);
	preOrderTraverse(root->right);
}

void postOrderTraverse(Node *root)
{
	if(root==NULL) return;
	postOrderTraverse(root->left);
	postOrderTraverse(root->right);
	printf("%d ", root->data);
}

void inOrderTraverse(Node *root)
{
	if(root==NULL) return;
	inOrderTraverse(root->left);
	printf("%d ", root->data);
	inOrderTraverse(root->right);
}

Node *cloneTree(Node *root)
{
	
	


int main()
{
	Node *root = createTheTree();
	preOrderTraverse(root);		newl;
	postOrderTraverse(root);	newl;
	inOrderTraverse(root);		newl;
	return 0;
	
}
