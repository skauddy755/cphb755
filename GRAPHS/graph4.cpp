#include<bits/stdc++.h>
#define int long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
#define log1(a) for(auto x:a)cout << x <<" ";cout <<endl;
#define log2(a,r,c) for(int i=0;i<r;i++){for(int j=0;j<c;j++)cout<<a[i][j]<<" ";cout << endl;}

using namespace std;
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};

/*
Examples used:
===================================
without cycle:
9 10
1 2
1 8
2 5
2 9
3 4
4 5
4 8
5 7
5 9
6 7

with cycle:
9 11
1 2
1 8
2 5
2 9
3 4
4 5
4 8
5 1
5 7
5 9
6 7

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

// Using Kahn's Algorithm:
bool topoSort(vector<vector<int>> adj, vector<int> inDeg, vector<int> &topo)
{
	// NOTE:
	// 1). TopoSort is not unique
	// 2). TopoSort is not possible when there is a cycle
	
	int n = adj.size() - 1;
	queue<int> q;
	for(int i=1; i<=n; i++)
	{
		if(inDeg[i] == 0) q.push(i);
	}
	
	while(!q.empty())
	{
		int node = q.front();
		topo.push_back(node);
		q.pop();
		
		for(auto child : adj[node])
		{
			inDeg[child]--;
			if(inDeg[child] == 0) q.push(child);
		}
	}
	
	if(topo.size() != n)
	{
		topo = vector<int>(0);
		return false;
	}
	return true;
}
int32_t main()
{
	fastio
	
	int n; cin >> n; // Num of nodes
	int m; cin >> m; // Num of edges
	vector<vector<int>> adj(n+1, vector<int>(0));
	vector<int> inDeg(n+1, 0);
	for(int i=0; i<m; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		inDeg[b]++;
	}
	print_unw(n, m, adj);
	
	vector<int> topo;
	cout << "isPossible = " << topoSort(adj, inDeg, topo) << endl;
	log1(topo);
	
	return 0;
}