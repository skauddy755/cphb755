#include<bits/stdc++.h>
#define int long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
#define log1(a) for(auto x:a)cout << x <<" ";cout <<endl;
#define log2(a,r,c) for(int i=0;i<r;i++){for(int j=0;j<c;j++)cout<<a[i][j]<<" ";cout << endl;}

using namespace std;
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};

/*
Example:
===============

7 8
1 2
2 3
3 1
4 3
5 6
6 7
7 4
7 5

*/

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

void dfs1(int node, vector<vector<int>> adj, vector<bool> &visited, vector<int> &arr)
{
	visited[node] = true;
	for(auto child: adj[node])
	{
		if(visited[child]) continue;
		dfs1(child, adj, visited, arr);
	}
	arr.push_back(node);
}

void dfs2(int node, vector<vector<int>> adj, vector<bool> &visited, vector<int> &sscArr)
{
	visited[node] = true;
	for(auto child: adj[node])
	{
		if(visited[child]) continue;
		dfs2(child, adj, visited, sscArr);
	}
	sscArr.push_back(node);
}

void kosoraju_ssc(vector<vector<int>> adj)
{
	int n = adj.size() - 1;
	
	// apply dfs1 in the original graph
	vector<bool> visited(n+1, false);
	vector<int> arr;
	for(int i=1; i<=n; i++)
	{
		if(!visited[i]) dfs1(i, adj, visited, arr);
	}
	cout << "\ndfs arr (inc. outTime):\n"; log1(arr); cout << endl;
	
	// reset visited status to false
	visited = vector<bool>(n+1, false);
	
	// apply dfs2 on the transposed graph
	cout << "\nPrinting the SSC:\n"; log1(arr); cout << endl;
	for(int i=1; i<=n; i++)
	{
		if(visited[i]) continue;
		
		vector<int> sscArr;
		dfs2(i, adj, visited, sscArr);
		cout << "\ndfs2 at: " << i << endl;
		log1(sscArr);
	}
}

int32_t main()
{
	fastio
	
	int n; cin >> n; // Num of nodes
	int m; cin >> m; // Num of edges
	vector<vector<int>> adj(n+1, vector<int>(0));
	vector<vector<int>> adjTr(n+1, vector<int>(0));
	for(int i=0; i<m; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adjTr[b].push_back(a);
	}
	print_unw(n, m, adj); cout << endl;
	print_unw(n, m, adjTr);
	
	cout << "\nFinding SSC:\n" << endl;
	kosoraju_ssc(adj);
	
	return 0;
}