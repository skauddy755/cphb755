#include<bits/stdc++.h>
#define int long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
#define log1(a) for(auto x:a)cout << x <<" ";cout <<endl;
#define log2(a,r,c) for(int i=0;i<r;i++){for(int j=0;j<c;j++)cout<<a[i][j]<<" ";cout << endl;}

using namespace std;
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};

/*
Example Used (TREE):
====================
8 7
1 2
1 3
2 5
2 6
4 5
4 8
6 7

*/

vector<int> dist;

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

void dfs_d(int node, vector<vector<int>> adj, vector<bool> &visited, vector<int> &dist, vector<int> &par)
{
	visited[node] = true;
	for(auto child : adj[node])
	{
		if(visited[child]) continue;
		
		dist[child] = dist[node] + 1;
		par[child] = node;
		dfs_d(child, adj, visited, dist, par);
	}
}

vector<vector<int>> gen_sparseTable(vector<vector<int>> adj, int src)
{
	int n = adj.size() - 1;
	
	dist = vector<int>(n+1, 0);
	vector<bool> visited(n+1, false);
	vector<int> par(n+1, 0);
	dfs_d(src, adj, visited, dist, par);
	
	int maxLevel = ceil(log(*max_element(dist.begin(), dist.end())) / log(2));
	
	vector<vector<int>> sparse(n+1, vector<int>(maxLevel + 1));
	for(int i=1; i<=n; i++) sparse[i][0] = par[i];
	for(int j=1; j<=maxLevel; j++)
	{
		for(int i=1; i<=n; i++) sparse[i][j] = sparse[sparse[i][j-1]][j-1];
	}
	
	return sparse;
}



int find_LCA(int a, int b, int src, vector<vector<int>> sparse)
{
	if(dist[a] < dist[b])
	{
		int temp = a;
		a = b;
		b = temp;
	}
	
	int diff = dist[a] - dist[b]; // assuming a is deeper than b
	int placeValue = 0;
	while(diff != 0)
	{
		int bit = diff & 1;
		if(bit == 1) a = sparse[a][placeValue];
		
		diff = diff >> 1;
		placeValue++;
	}
	
	if(a == b) return a;
	
	while(a != b)
	{
		a = sparse[a][0];
		b = sparse[b][0];
	}
	
	return a;
}

int32_t main()
{
	fastio
	
	int n; // Num of nodes
	int m; // Num of edges
	cin >> n >> m;
	
	vector<vector<int>> adj(n+1, vector<int>(0));
	
	for(int i=0; i<m; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	cout << "\nAdjacency List:\n";
	print_unw(n, m, adj);
	
	// Generating sparse Table (for a TREE):
	cout << "\nGenerating sparse table:\n";
	int src = 1;
	vector<vector<int>> sparse = gen_sparseTable(adj, src);
	log2(sparse, sparse.size(), sparse[0].size());
	cout << "\n===================================\n";
	
	
	
	// Lowest Common Ancestor (in a TREE):
	cout << "\nLowest Common ancestor:\n";
	int a = 7, b = 3;
	cout << "LCA = " << find_LCA(a, b, src, sparse) << endl;
	cout << "\n===================================\n";
	
	
	
	// Distance between 2 nodes (in a TREE):
	cout << "\nDistance between 2 nodes\n";
	int d = dist[a] + dist[b] - 2 * dist[find_LCA(a,b,src,sparse)];
	cout << "distance = " << d << endl;
	cout << "\n===================================\n";
	
	
	return 0;
}