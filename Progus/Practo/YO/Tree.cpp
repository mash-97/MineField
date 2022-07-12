#include <iostream>
#include <stdio.h>
using namespace std;

template <class Type>
class BST
{
	private:
		struct Node
		{
			Type data;
			Node *parent;
			Node *left;
			Node *right;
		};
		Node * createNode(Type data)
		{
			Node * new_node = new Node;
			new_node->data = data;
			new_node->parent = NULL;
			new_node->left = NULL;
			new_node->right = NULL;
			return new_node;
		}
		Node * createNode(Type data, Node *parent, Node *left, Node *right)
		{
			Node * new_node = new Node;
			new_node->data = data;
			new_node->parent = parent;
			new_node->left = left;
			new_node->right = right;
			return new_node;
		}
		void addLeftChild(Node *parent_node, Node *node)
		{
			parent_node->left = node;
			if(node!=NULL) node->parent = parent_node;
		}
		void addLeftChild(Node *node, Type data)
		{
			Node * new_node = createNode(data);
			addLeftChild(node, new_node);
		}
		
		void addRightChild(Node *parent_node, Node *node)
		{
			parent_node->right = node;
			if(node!=NULL) node->parent = parent_node;
		}
		
		void addRightChild(Node *node, Type data)
		{
			Node * new_node = createNode(data);
			addRightChild(node, new_node);
		}
		
		void preTraverse(Node *node)
		{
			if(node==NULL) return;
			cout<<node->data<<" ";
			if(node->left!=NULL) preTraverse(node->left);
			if(node->right!=NULL) preTraverse(node->right);
		}
		
		void inTraverse(Node *node)
		{
			if(node==NULL) return;
			if(node->left!=NULL) inTraverse(node->left);
			cout<<node->data<<" ";
			if(node->right!=NULL) inTraverse(node->right);
		}
		
		void postTraverse(Node *node)
		{
			if(node==NULL) return;
			if(node->left!=NULL) postTraverse(node->left);
			if(node->right!=NULL) postTraverse(node->right);
			cout<<node->data<<" ";
		}
		Node * searchNode(Type data)
		{
			Node *c = root;
			while(c!=NULL)
			{
				if(c->data == data) return c;
				else if(c->data > data) c = c->left;
				else c = c->right;
			}
			return NULL;
		}
		Node * minimumNode()
		{
			if(root==NULL) return NULL;
			Node *c = root;
			while(c->left!=NULL) c = c->left;
			return c;
		}
		Node * minimumNodeOf(Node *node)
		{
			if(root==NULL || node==NULL) return NULL;
			Node *c = node;
			while(c->left!=NULL) c = c->left;
			return c;
		}
		Node * maximumNode()
		{
			if(root==NULL) return NULL;
			Node *c = root;
			while(c->right!=NULL) c = c->right;
			return c;
		}
		Node * maximumNodeOf(Node *node)
		{
			if(root==NULL || node==NULL) return NULL;
			Node *c = node;
			while(c->right!=NULL) c = c->right;
			return c;
		}
		void transplantNode(Node *node, Node *new_node)
		{
			if(node == root)
				root = new_node;
			
			else if(node->parent->left == node)
				addLeftChild(node->parent, new_node);
				
			else
				addRightChild(node->parent, new_node);
		}
		
		void deleteNode(Node *node)
		{
			if(node->left == NULL)
				transplantNode(node, node->right);
			
			else if(node->right == NULL)
				transplantNode(node, node->left);
				
			else
			{
				Node *successor_node = minimumNodeOf(node->right);
				
				if(successor_node->parent != node)
				{
					transplantNode(successor_node, successor_node->right);
					addRightChild(successor_node, node->right);
				}
				
				transplantNode(node, successor_node);
				addLeftChild(successor_node, node->left);
			}
			free(node);
		}
				
			
			
			
			
		
	public:
		bool print_message;
		Node *root;
		
		BST()
		{
			this->root = NULL;
			this->print_message = false;
		}
		BST(int length, Type *array)
		{
			this->root = NULL;
			this->print_message = false;
			this->bstifyArray(length, array);
		}
		BST(int length, Type *array, bool print_message)
		{
			this->root = NULL;
			this->print_message = print_message;
			this->bstifyArray(length, array);
		}
		void insert(Type data)
		{
			Node *new_node = createNode(data);
			if(root==NULL)
			{
				root = new_node;
				return;
			}
			Node *c = root, *parent_node = NULL;
			while(c!=NULL)
			{
				parent_node = c;
				if(c->data > new_node->data)
					c = c->left;
				else
					c = c->right;
			}
			
			if(parent_node->data > new_node->data)
			{
				if(print_message)
					cout<<" adding: "<<new_node->data<<" as left child to the parent: "
						<<parent_node->data<<endl;
				addLeftChild(parent_node, new_node);
			}

			else 
			{
				if(print_message)
					cout<<" adding: "<<new_node->data<<" as right child to the parent: "
						<<parent_node->data<<endl;
				addRightChild(parent_node, new_node);
			}
				
		}
		
		void bstifyArray(int length, Type *array)
		{
			for(int i=0; i<length; i++)
				insert(array[i]);
		}
		
		void traverse(int traverse_value=0)
		{
			if(traverse_value==-1)
				preTraverse(root);
			else if(traverse_value==0)
				inTraverse(root);
			else
				postTraverse(root);
			puts("");
		}
		bool search(Type data)
		{
			Node *result_node = searchNode(data);
			if(result_node!=NULL) return true;
			return false;
		}
		Type miniman()
		{
			Node *c = minimumNode();
			if(c==NULL) return -(int)__builtin_inf();
			return c->data;
		}
		Type maximan()
		{
			Node *c = maximumNode();
			if(c==NULL) return (int)__builtin_inf();
			return c->data;
		}
		
		void deleteData(Type data)
		{
			Node *node = searchNode(data);
			if(node!=NULL) 
				deleteNode(node);
		}
};

int main()
{
	// Give an array with n elements and bstify the array.
	int n;
	scanf("%d", &n);
	int array[n];
	for(int i=0; i<n; i++)
		scanf("%d", &array[i]);
	
	
	BST<int> bst(n, array, true);
	// Print the internel messages
	bst.print_message = true;
	
	printf("Pre-order traverse: ");
	bst.traverse(-1);
	puts("");
	
	printf("In-order traverse: ");
	bst.traverse(0);
	puts("");
	
	printf("Post-order traverse: ");
	bst.traverse(1);
	puts("");
	
	printf("Minima: ");
	cout<<bst.miniman()<<endl;
	puts("");
	printf("Maxima: ");
	cout<<bst.maximan()<<endl;
	puts("");
	g:
	printf("Search For delete: ");
	scanf("%d", &n);
	if(bst.search(n))
	{
		bst.deleteData(n);
		printf("Found! and deleted!\n");
		printf("In-order Traverse: ");
		bst.traverse(0);
		puts("");
		printf("Pre-order Traverse: ");
		bst.traverse(-1);
		puts("");
	}
	else printf("Not found!\n");
	if(n>0) goto g;
	
	return 0;
}
			
			
	
