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
	
	
	// SIMPLE BFS:
	//-----------------------------------------------------------------
	/*cout << "\nSimple BFS :\n";
	int src = 2;
	bfs(src, adj);
	cout << "\n===============================\n";*/
	
	
	// Single source shortest path BFS:
	//-----------------------------------------------------------------
	cout << "\nSSSP using BFS :\n";
	int src = 3;
	log1(bfs_ssspGraph(src, adj));
	cout << "\n===============================\n";
	
	
	
	return 0;
}