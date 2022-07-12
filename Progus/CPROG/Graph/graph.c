#include <stdio.h>
#include <stdlib.h>

typedef struct Node N;
struct Node
{
	int data;
	N * next;
}

typedef struct LNode LN;
struct LNode
{
	N * node;
	LN * adjacency_node;
