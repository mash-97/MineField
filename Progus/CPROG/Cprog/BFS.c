#include <stdio.h>
#include <stdlib.h>

#define RED 1001
#define GREY 1005
#define BLACK 1010

typedef struct Node  N;
struct Node
{
	int data;
	int color;
	N * adjacency_list;
	N * next;
};


N * create_a_node(int data, N * adjacency_list, N * next)
{
	N * new_node = (N *) malloc(sizeof(N));
	
	new_node->color = RED;
	new_node->data = data;
	new_node->adjacency_list = adjacency_list;
	new_node->next = next;
	
	return new_node;
}


N * add_to_the_last_of_the_list(N * list, N * node)
{
	if(list == NULL) return node;
	N * current_node = list;

	while(current_node->next != NULL) current_node = current_node->next;
	current_node->next = node;

	return list;
}

N * find_node(N * list, int data)
{
	N * c = list;
	while(c!=NULL)
	{
		if(c->data == data) return c;
		c = c->next;
	}
	return c;
}

void add_an_adjacency_node(N * node, N * adjacency_node)
{
	if(node==NULL || adjacency_node==NULL) return;
	node->adjacency_list = add_to_the_last_of_the_list(node->adjacency_list, adjacency_node);
}

typedef struct Graph G;
struct Graph
{
	N * nodes;
};


G * create_a_graph(N * nodes)
{
	G * new_graph = (G *) malloc(sizeof(G));
	new_graph->nodes = nodes;
	return new_graph;
}


void add_nodes_to_the_graph(G * g, N * node)
{
	g->nodes = add_to_the_last_of_the_list(g->nodes, node);
}


void print_graph(G * g)
{
	N * current_node = g->nodes;
	while(current_node!=NULL)
	{
		printf("%d => ", current_node->data);
		N * adjacency_node = current_node->adjacency_list;
		while(adjacency_node != NULL)
		{
			if(adjacency_node->next != NULL) printf("%d -> ", adjacency_node->data);
			else printf("%d\n", adjacency_node->data);
			adjacency_node = adjacency_node->next;
		}
		printf("\n");
		current_node = current_node->next;
	}
	puts("");
}

N * find_a_node_from_the_graph_by_data(G * graph, int data)
{
	return find_node(graph->nodes, data);
}

typedef struct Queue Q;
struct Queue
{
	N * head;
	N * tail;
};

Q * initialize_a_queue()
{
	Q * q = (Q*) malloc(sizeof(Q));
	q->head = NULL;
	q->tail = NULL;
	return q;
}

Q * enqueue(Q * queue, N * node)
{
	if(queue == NULL) return NULL;
	if(queue->head == NULL)
	{
		queue->head = node;
		queue->tail = node;
	}
	else
	{
		queue->tail->next = node;
		queue->tail = node;
	}
	return queue;
}

N * dequeue(Q * queue)
{	
	if(queue->head == NULL) return NULL;
	
	N * node = queue->head;
	if(queue->head == queue->tail) 
	{
		queue->head = NULL;
		queue->tail = NULL;
	}
	else queue->head = queue->head->next;
	
	node->next = NULL;
	return node;
}

typedef struct Tree T;
struct Tree
{
	N * nodes;
};

T * initialize_a_tree()
{
	T * new_tree = (T*) malloc(sizeof(T));
	new_tree->nodes = NULL;
	return new_tree;
}

T * add_node_to_the_tree(T * tree, N * before_node, N * node)
{
	if(tree->nodes == NULL || before_node == NULL)
	{
		tree->nodes = node;
		return tree;
	}
	
	before_node->next = node;
	return tree;
}

N * ccopy_node(N * node)
{
	N * new_node = create_a_node(node->data, NULL, NULL);
	return new_node;
}

Q * enqueue_red_adjacencies(Q * queue, N * adjacency_list)
{
	N * c = adjacency_list;
	while(c!=NULL)
	{
		if(c->color == RED)
		{
			c->color = GREY;
			queue = enqueue(queue, c);

		}
		c = c->next;
	}
	return queue;
}

T * ccopy_and_add_to_the_tree_adjacencies(T * tree, N * node, N * c_node)
{
	if(tree == NULL)
	{
		tree->nodes = c_node;
		return tree;
	}
	
	N * c = node->adjacency_list;
	while(c!=NULL)
	{
		if(c->color == RED) 
		{
			c->color = GREY;
			tree = add_node_to_the_tree(tree, c_node, ccopy_node(c));
		}
		c = c->next;
	}
	return tree;
}

T * make_a_bfs_tree(N * node, T * tree, N * c_node)
{
	if(node==NULL || node->color == BLACK) return tree;
	
	if(tree == NULL)	
	{
		node->color = BLACK;
		tree = initialize_a_tree();
		tree = add_node_to_the_tree(tree, NULL, c_node);
	}
	
	tree = ccopy_and_add_to_the_tree_adjacencies(tree, node, c_node);
	
	N * c = node->adjacency_list;
	while(c!=NULL)
	{
		if(c->color == GREY)
			tree = make_a_bfs_tree(node, tree, c_node);
		c = c->next;
	}
	return tree;
}
	
	
	
void pre_traverse_the_tree(N * node)
{
		if(node==NULL) return;
		printf("%d ", node->data);
		N * c = node->adjacency_list;
		while(c!=NULL)
		{
			pre_traverse_the_tree(c);
			c = c->next;
		}
	puts("");
}

int main()
{
	char s[5] = {'a', 'b', 'c', 'd', 'e'};
	s[3] = '\n';
	printf("%s\n", s);
	int m, data, total_adj;
	G * graph = create_a_graph(NULL);
	N * node = NULL;
	N * adj_node = NULL;
	
	printf("Total Nodes: ");
	scanf("%d", &m);
	
	for(int i=1; i<=m; i++)
	{
		printf("%d => ", i);
		node = create_a_node(i, NULL, NULL);
		add_nodes_to_the_graph(graph, node);
		
		scanf("%d", &total_adj);
		for(int j=1; j<=total_adj; j++)
		{
			scanf("%d", &data);
			adj_node = create_a_node(data, NULL, NULL);
			node->adjacency_list = add_to_the_last_of_the_list(node->adjacency_list, adj_node);
		}
		printf("\n");
	}
	
	puts("The Graph: ");
	print_graph(graph);
	puts("");
	T * tree = make_a_bfs_tree(graph->nodes, NULL, ccopy_node(graph->nodes));
	puts("The BFS Tree: ");
	pre_traverse_the_tree(tree->nodes);
	puts("");
	puts("The Graph: ");
	print_graph(graph);
	return 0;
}
	
