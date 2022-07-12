#include <stdio.h>
#include <stdlib.h>

typedef struct Node N;
struct Node
{
	int data;
	N * next;
};

typedef struct List L;
struct List
{
	int data;
	N * adjacency_nodes;
};

N * create_node(int data, N * next)
{
	N * n = (N*) malloc(sizeof(N));
	n->data = data;
	n->next = next;
	return n;
}

L * create_list(int data, N * adjacency_nodes)
{
	L * l = (L*) malloc(sizeof(L));
	l->data = data;
	l->adjacency_nodes = adjacency_nodes;
	return l;
}

N * insert_last(N * nodes, N * node)
{
	if(nodes == NULL) return node;
	N * c = nodes;
	while(c->next)	c = c->next;
	c->next = node;
	return nodes;
}

void print_adjacency_list(N * nodes)
{
	N * c = nodes;
	while(c) 
	{
		printf("%d ", c->data);
		c = c->next;
	}
	puts("");
}

void print_list(L * list[], int length)
{
	for(int i=0; i<length; i++)
	{
		printf("%d => ", list[i]->data);
		print_adjacency_list(list[i]->adjacency_nodes);
	}
	puts("");
}

int main()
{
	int n, e, m;
	scanf("%d", &n);
	
	L * lists[n];
	N * nodes = NULL;
	for(int i=0; i<n; i++)
	{
		printf("%d => ", i+1);
		scanf("%d", &e);
		nodes = NULL;
		for(int j=1; j<=e; j++)
		{
			scanf("%d", &m);
			nodes = insert_last(nodes, create_node(m, NULL));
		}
		lists[i] = create_list(i+1, nodes);
	}
	
	puts(".");
	print_list(lists, n);
	
	return 0;
}
	

