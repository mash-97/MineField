#include <stdio.h>

#define true 1
#define false 0

void DFSDriver(int V, int S, int Graph[][V], char *visited)
{
	visited[S] = true;
	printf("%d ", S+1);
	for(int i=0; i<V; i++)
		if(Graph[S][i] && !visited[i])
			DFSDriver(V, i, Graph, visited);
}

void DFS(int V, int S, int Graph[][V])
{
	char visited[V];
	for(int i=0; i<V; i++) visited[i] = false;
	DFSDriver(V, S, Graph, visited);
	printf("\n");
}

int main()
{
	int V;
	scanf("%d", &V);
	
	int Graph[V][V];
	for(int i=0; i<V; i++) 
		for(int j=0; j<V; j++) 
			Graph[i][j] = false;
	int E, source;
	int v, w;
	scanf("%d", &E);
	
	for(int i=0; i<E; i++)
	{
		scanf("%d %d", &v, &w);
	
		Graph[v-1][w-1] = true;
	}
	scanf("%d", &source);
	
	DFS(V, source-1, Graph);
	return 0;
}
