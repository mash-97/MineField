#include <stdio.h>

int graph[201][201];
int visited[201];


void visit(int i, int n, int graph[n+1][n+1], int visited[n+1]){
	if(visited[i]) return;
	visited[i] = 1;
	for(int x=0; x<=n; x++)
		if(graph[i][x])
			visit(x, n, graph, visited);
}

void visitg(int i, int n){	
	if(visited[i]) return;
	visited[i] = 1;
	for(int x=0; x<=n; x++)
		if(graph[i][x])
			visitg(x, n);
}


int isAllVisited(int n, int visited[n+1]){
	for(int i=0; i<=n; i++)
		if(!visited[i])
			return 0;
	return 1;
}

void printGraph(int n){
	printf("\nGraph: \n");
	for(int i=0; i<=n; i++)
	{
		for(int j=0; j<=n; j++)
			printf("%d\t", graph[i][j]);
		printf("\n");
	}
	printf("\n");
}

void printVisited(int n){
	printf("\nvisited: \n");
	for(int i=0; i<=n; i++)
		printf("%d\t", visited[i]);
	printf("\n");
}

int main(){
	int T;
	scanf("%d", &T);
	
	while(T--){
		//printf("\n");
		int N, M;
		scanf("%d%d", &N, &M);
		//~ int graph[N+1][N+1];
		//~ int visited[N+1];
		for(int i=0; i<=N; i++)
		{
			visited[i] = 0;
			for(int j=0; j<=N; j++)
				graph[i][j]=0;
		}
		while(M--){
			int a, b;
			scanf("%d%d", &a, &b);
			graph[a][b] = 1;
			graph[b][a] = 1;
		}
		//~ printGraph(N);
		//~ printVisited(N);
		//~ visit(0, N, graph, visited);
		visitg(0, N);
		//~ printGraph(N);
		//~ printVisited(N);
		
		if(isAllVisited(N, visited))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
