#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>> adj, vector<bool> &visited)
{
	visited[node] = true; cout << node << "\n";
	for(auto child: adj[node])
	{
		if(visited[child]) continue;
		dfs(child, adj, visited);
	}
}
/*
void bfs(int src, vector<pair<int,int>> adj[], int n, bool &visited[])
{
	queue<int> q;
	q.push(src);
	while(!q.empty())
	{
		int node = q.front();
		q.pop();
		for(auto p: adj[node])
		{
			int child = p.first;
			int w = p.second;
			visited[child] = true; cout << child << "\n";
			q.push(child);
		}
	}
}
*/


int main()
{
	
	
	return 0;
}