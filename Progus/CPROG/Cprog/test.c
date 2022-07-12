#include <stdio.h>
#include <stdlib.h>

typedef struct Node  N;
struct Node
{
	int data;
	N * adjacency_list;
	N * next;
};


N * create_a_node(int data, N * adjacency_list, N * next)
{
	N * new_node = (N *) malloc(sizeof(N));
	
	new_node->data = data;
	new_node->adjacency_list = adjacency_list;
	new_node->next = next;
	
	return new_node;
}

int main()
{
	return 0;
}
