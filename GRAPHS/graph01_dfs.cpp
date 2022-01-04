#include<bits/stdc++.h>
#define int long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
#define log1(a) for(auto x:a)cout << x <<" ";cout <<endl;
#define log2(a,r,c) for(int i=0;i<r;i++){for(int j=0;j<c;j++)cout<<a[i][j]<<" ";cout << endl;}

using namespace std;
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};

//===============================================================
//===============================================================

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

/*
Example used:
=============

#1 : Tree : n=5, m=4
-----------------------
1 2
2 4
4 5
2 3

#2 : Graph : n=5, m=5
-----------------------
1 2
2 4
4 5
2 3
3 4

#3 : Tree : n=7, m=6
-----------------------
1 2
2 3
2 4
3 7
4 5
4 6

#4 : Graph : n=10, m=7 {for cc__dfs()}
1 3
1 4
2 4
3 4
3 5
6 7
9 10

*/

void dfs(int node, vector<vector<int>> adj, vector<bool> &visited)
{
	visited[node] = true; cout << node << " ";
	for(auto child: adj[node])
	{
		if(visited[child]) continue;
		dfs(child, adj, visited);
	}
}

void cc__dfs(int n, vector<vector<int>> adj, vector<bool> &visited)
{
	int numcc = 0;
	cout << "\nCC\n";
	for(int i=1; i<=n; i++)
	{
		if(!visited[i])
		{
			cout << "\nCC = " << i << endl;
			numcc++;
			dfs(i, adj, visited);
			cout << endl;
		}
	}
	cout << "\nNumber of CC = " << numcc << "\n";
}

bool dfs_checkBipartile(int node, vector<vector<int>> adj, vector<bool> &visited, vector<bool> &color, bool c)
{
	visited[node] = true;
	color[node] = c;
	
	for(auto child : adj[node])
	{
		if(!visited[child])
		{
			bool f = dfs_checkBipartile(child, adj, visited, color, !c);
			if(!f) return false;
		}
		else
		{
			if(color[child] == color[node]) return false;
		}
	}
	return true;
}

void dfs_ssspTree(int node, vector<vector<int>> adj, vector<bool> &visited, vector<int> &distance)
{
	visited[node] = true;
	for(auto child : adj[node])
	{
		// Although not required to check that condition (since TREES)
		if(visited[child]) continue;
		
		int w = 1;
		distance[child] = distance[node] + w;
		dfs_ssspTree(child, adj, visited, distance);
	}
}

bool dfs_cycleDetection(int node, vector<vector<int>> adj, vector<bool> &visited, int par)
{
	visited[node] = true;
	for(auto child : adj[node])
	{
		if(!visited[child])
		{
			int f = dfs_cycleDetection(child, adj, visited, node);
			if(f) return true;
		}
		else
		{
			if(child != par) return true;
		}
	}
	return false;
}

// #3
void dfs_ioTime(int node, vector<vector<int>> adj, vector<bool> &visited, vector<int> &inTime, vector<int> &outTime, int &timer)
{
	// Stay in a node is instantaneous time.
	// time interval (1 sec) is required for moving along an edge.
	cout << timer << " ";
	visited[node] = true;
	inTime[node] = timer;
	// inTime = time instant at which this node is first reached by its parent
	
	// time to travel the subtree of node
	// if no subtree, then no increment in time.
	for(auto child : adj[node])
	{
		if(visited[child]) continue;
		dfs_ioTime(child, adj, visited, inTime, outTime, ++timer);
	}
	outTime[node] = ++timer;
	// outTime = time at which control has reached the parent of this node
	// 1 sec to go back from node to par
}

int diameter__dfs(vector<vector<int>> adj)
{
	int n = adj.size() - 1;
	vector<bool> visited(n+1, false);
	vector<int> distance(n+1, 0);
	int src = 2;
	
	dfs_ssspTree(src, adj, visited, distance);
	log1(distance);
	int pos = max_element(distance.begin(), distance.end()) - distance.begin();
	cout << pos << "\n";
	
	distance = vector<int>(n+1, 0);
	visited = vector<bool>(n+1, false);
	dfs_ssspTree(pos, adj, visited, distance);
	log1(distance);
	int diam = *max_element(distance.begin(), distance.end());
	
	return diam;
}

int32_t main()
{
	fastio
	
	int n; cin >> n; // Num of nodes
	int m; cin >> m; // Num of edges
	vector<vector<int>> adj(n+1, vector<int>(0));
	for(int i=0; i<m; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	print_unw(n, m, adj); cout << endl;
	
	vector<bool> visited(n+1, false);
	
	// SIMPLE DFS:
	//-----------------------------------------------------------------
	/*cout << "\nSimple DFS :\n";
	dfs(2, adj, visited);
	cout << "\n===============================\n";*/
	
	
	
	// Counting number of Connected Components by calling DFS function:
	//-----------------------------------------------------------------
	/*cout << "\nCounting no of CC :\n";
	cc__dfs(n, adj, visited);
	cout << "\n===============================\n";*/
	
	
	
	// Checking the Bipartile Test:
	//-----------------------------------------------------------------
	/*cout << "\nChecking bipartile\n";
	vector<bool> color(n+1, false);
	bool isBp = dfs_checkBipartile(1, adj, visited, color, true);
	cout << isBp << "\n";
	log1(color);
	cout << "\n===============================\n";*/
	
	
		
	// Single source shortest shortest path on tree:
	//-----------------------------------------------------------------
	/*cout << "\nSSSP on tree\n";
	vector<int> distance(n+1, 0);
	int src = 2;
	dfs_ssspTree(src, adj, visited, distance);
	log1(distance);
	cout << "\n===============================\n";*/
	
	
	
	// Cycle Detection (Y/N):
	//-----------------------------------------------------------------
	/*cout << "\nCycle Detection\n";
	bool hasCycle = dfs_cycleDetection(2, adj, visited, 0);
	cout << hasCycle << "\n";
	cout << "\n===============================\n";*/
	
	
	
	// in/out time (TREE and GRAPH both):
	//-----------------------------------------------------------------
	cout << "\nDFS in/out time:\n";
	vector<int> inTime(n+1, 0);
	vector<int> outTime(n+1, 0);
	int src = 1;
	int timer = 1;
	dfs_ioTime(src, adj, visited, inTime, outTime, timer);
	cout << endl;
	log1(inTime);
	log1(outTime);
	cout << "\n===============================\n";
	
	
	
	// Diameter of a tree using DFS
	//-----------------------------------------------------------------
	/*cout << "\nDiameter of a tree using dfs_ssspTree():\n";
	int diam = diameter__dfs(adj);
	cout << "\n" << diam;
	cout << "\n===============================\n";*/
	
	
	
	return 0;
}