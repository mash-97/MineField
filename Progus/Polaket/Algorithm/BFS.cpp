#include <iostream>
#include <list>

using namespace std;

class Graph
{
	int V;
	
	list<int> *adj;
	
	public:
	Graph(int V);
	void addEdge(int v, int w);
	void BFS(int s);
};

Graph::Graph(int v)
{
	this->V = v;
	this->adj = new list<int>[v];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
}

void Graph::BFS(int s)
{
	// Mark all the vertices as not visited
	bool *visited = new bool[V];
	for(int i=0; i<V; i++)	visited[i] = false;
	
	// Create a queue for BFS
	list<int> queue;
	
	// Mark the current node as visited and enqueue it
	visited[s] = true;
	queue.push_back(s);
	
	// 'i' will be used to get all adjacent
	// vertices of a vertex
	list<int>::iterator i;
	
	while(!queue.empty())
	{
		// Dequeue a vertex from queue and print it
		s = queue.front();
		cout << s << " ";
		queue.pop_front();
		
		// Get all adjacent vertices of the dequeued
		// vertex s. If a adjacent has not been visited,
		// then mark if visited and enqueue it
		for(i=adj[s].begin(); i!=adj[s].end(); ++i)
		{
			if(!visited[*i])
			{
				visited[*i] = true;
				queue.push_back(*i);
			}
		}
	}
}

// Driver program to test methods of graph class
int main()
{
	Graph g(8);
	g.addEdge(1, 3);
	g.addEdge(1, 5);
	g.addEdge(3, 1);
	g.addEdge(3, 5);
	g.addEdge(5, 1);
	g.addEdge(5, 7);
	g.addEdge(7, 1);
	g.addEdge(7, 3);
	
	cout << "Following is Breadth First Traversal "
		 << "(starting from vertex 2)\n";
	g.BFS(1);
	
	return 0;
}
	
	
