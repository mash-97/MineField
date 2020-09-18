#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

vector<vector<int>> static_graph()
{
	// undirected graph
	vector<vector<int>> graph;
	
	// it will create 6 nodes;
	// first create 6 vectors as nodes and push adjacents 
	// on the way.
	vector<int> n0;
	n0.push_back(1);
	n0.push_back(2);
	n0.push_back(4);
	graph.push_back(n0);
	
	vector<int> n1; 
	n1.push_back(0);
	n1.push_back(3);
	n1.push_back(5);
	n1.push_back(8);
	graph.push_back(n1);
	
	vector<int> n2;
	n2.push_back(0);
	n2.push_back(3);
	graph.push_back(n2);
	
	vector<int> n3;
	n3.push_back(1);
	n3.push_back(2);
	graph.push_back(n3);
	
	vector<int> n4;
	n4.push_back(0);
	n4.push_back(5);
	graph.push_back(n4);
	
	vector<int> n5;
	n5.push_back(1);
	n5.push_back(4);
	graph.push_back(n5);
	
	vector<int> n6;
	n6.push_back(7);
	graph.push_back(n6);
	
	vector<int> n7;
	n7.push_back(6);
	n7.push_back(8);
	graph.push_back(n7);
	
	vector<int> n8;
	//~ n8.push_back(1);
	//~ n8.push_back(7);
	graph.push_back(n8);
	
	return graph;
}
	
int count_components_by_dfs(vector<vector<int>> graph)
{
	int count = 0;
	
	// nodes to check if visited
	int node[(int)graph.size()];
	for(int i=0; i<(int)graph.size(); i++)
		node[i] = 1;
	
	stack<int> s;
	int top;
	
	for(int i=0; i<(int)graph.size(); i++)
	if(node[i]) 
	{
		node[i] = 0;
		count += 1;
		s.push(i);
		
		while(!s.empty()) 
		{
			top = s.top();
			s.pop();
			
			for(auto x : graph[top])
			if(node[x])
			{
				s.push(x);
				node[x] = 0;
			}
		}
	}
	
	return count;
}


int count_components_by_bfs(vector<vector<int>> graph)
{
	int count = 0;
	
	// nodes to check if visited
	int node[(int)graph.size()];
	for(int i=0; i<(int)graph.size(); i++)
		node[i] = 1;
	
	queue<int> q;
	int front;
	
	for(int i=0; i<(int)graph.size(); i++)
	if(node[i]) 
	{
		node[i] = 0;
		count += 1;
		q.push(i);
		
		while(!q.empty()) 
		{
			front = q.front();
			q.pop();
			
			for(auto x : graph[front])
			if(node[x])
			{
				q.push(x);
				node[x] = 0;
			}
		}
	}
	
	return count;
}

int main()
{
	vector<vector<int>> graph = static_graph();
	cout << count_components_by_bfs(graph) << endl;
	return 0;
}
