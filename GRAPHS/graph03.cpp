#include<bits/stdc++.h>
#define int long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
#define log1(a) for(auto x:a)cout << x <<" ";cout <<endl;
#define log2(a,r,c) for(int i=0;i<r;i++){for(int j=0;j<c;j++)cout<<a[i][j]<<" ";cout << endl;}

using namespace std;
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};


void print_unw(int n, int m, vector<vector<int>> adj)
{
	for(int i=1; i<=n; i++)
	{
		cout << i;
		for(int child : adj[i])
		{
			cout << " -> " << child;
		}
		cout << "\n";
	}
}

void dfs(int node, vector<vector<int>> adj, vector<bool> &visited)
{
	visited[node] = true; cout << node << "\n";
	for(auto child: adj[node])
	{
		if(visited[child]) continue;
		dfs(child, adj, visited);
	}
}

void bfs(int src, vector<vector<int>> adj)
{
	int n = adj.size() - 1;
	vector<bool> visited(n+1, false);
	queue<int> q;
	
	q.push(src);
	visited[src] = true;
	cout << src << " processing...\n"; // process the src node
	
	while(!q.empty())
	{
		int node = q.front();
		q.pop();
		
		for(auto child : adj[node])
		{
			if(visited[child]) continue;
			
			q.push(child);
			visited[child] = true;
			cout << child << " processing...\n"; // process node
		}
	}
}

vector<int> bfs_ssspGraph(int src, vector<vector<int>> adj)
{
	int n = adj.size() - 1;
	vector<bool> visited(n+1, false);
	vector<int> distance(n+1, 0);
	queue<int> q;
	
	q.push(src);
	visited[src] = true;
	cout << src << " processing...\n"; // process the src node
	
	while(!q.empty())
	{
		int node = q.front();
		q.pop();
		
		for(auto child : adj[node])
		{
			if(visited[child]) continue;
			
			q.push(child);
			visited[child] = true;
			cout << child << " processing...\n"; // process node
			int w = 1;
			distance[child] = distance[node] + w;
		}
	}
	
	return distance;
}

void dfs_bridges(int node, int par, vector<vector<int>> adj, vector<bool> &visited, vector<int> &inTime, vector<int> &lowTime, int &timer, vector<pair<int,int>> &bridges)
{
	visited[node] = true;
	inTime[node] = lowTime[node] = timer++;
	
	for(int child : adj[node])
	{
		if(child == par) continue;
		
		if(visited[child])
		{
			// Back edge
			lowTime[node] = min(lowTime[node], inTime[child]);
		}
		else
		{
			// Forward edge
			dfs_bridges(child, node, adj, visited, inTime, lowTime, timer, bridges);
			
			if(lowTime[child] > inTime[node])
			{
				bridges.push_back({node, child});
			}
			
			lowTime[node] = min(lowTime[node], lowTime[child]);
		}
	}
}

void dfs_articulationPoints(int node, int par, vector<vector<int>> adj, vector<bool> &visited, vector<int> &inTime, vector<int> &lowTime, int &timer, vector<int> art)
{ 
	visited[node] = true;
	inTime[node] = lowTime[node] = timer++;
	int numChildren = 0;
	for(int child : adj[node])
	{
		if(child == par) continue;
		
		
		if(visited[child])
		{
			lowTime[node] = min(lowTime[node], inTime[child]);
		}
		else
		{
			dfs_articulationPoints(child, node, adj, visited, inTime, lowTime, timer, art);
			
			lowTime[node] = min(lowTime[node], lowTime[child]);
			if(lowTime[child] >= inTime[node] && par != 0)
			{
				// child of node does not have a back edge to any ancestor of node
				// so node is an articulation point
				cout << node << " in \n";
			}
			numChildren++;
		}
	}
	if(par == 0 && numChildren > 1) cout << node << " out \n";
}

int32_t main()
{
	fastio
	
	int n; cin >> n; // Num of nodes
	int m; cin >> m; // Num of edges
	vector<vector<int>> adj(n+1, vector<int>());
	for(int i=0; i<m; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	print_unw(n, m, adj);
	
	
	// Finding backedges using DFS:
	//-----------------------------------------------------------------
	/*cout << "\nFinding bridges :\n";
	vector<bool> visited(n+1, false);
	vector<int> inTime(n+1, 0);
	vector<int> lowTime(n+1, 0);
	vector<pair<int,int>> bridges;
	int timer = 1;
	int src = 1;
	dfs_bridges(src, 0, adj, visited, inTime, lowTime, timer, bridges);
	for(auto edge : bridges) cout << edge.first << "--" << edge.second << "\n";
	cout << "\n===============================\n";*/
	
	
	
	// Finding Articulation points:
	//-----------------------------------------------------------------
	cout << "\nFinding Articulation points\n";
	vector<bool> visited(n+1, false);
	vector<int> inTime(n+1, 0);
	vector<int> lowTime(n+1, 0);
	vector<int> art;
	int src = 1;
	int timer = 1;
	dfs_articulationPoints(src, 0, adj, visited, inTime, lowTime, timer, art);
	
	cout << "\n===============================\n";
	
	
	
	return 0;
}