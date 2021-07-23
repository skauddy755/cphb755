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


/*
Graph:
------
13 16
1 2
1 5
1 6
1 7
2 3
2 4
3 4
5 8
5 9
5 10
5 12
6 7
8 9
10 11
10 12
12 13

*/

vector<vector<int>> adj;
vector<bool> vis;
vector<int> in, out, low;
int timer;


// finds the inTime, outTime, and lowTime
void dfs_iol(int node, int par){
	
	vis[node] = true;
	in[node] = low[node] = timer++;
	
	for(auto child : adj[node]) {
		if(vis[child]) {
			if(child != par) low[node] = min(low[node], in[child]);
			continue;
		}
		
		dfs_iol(child, node);
		low[node] = min(low[node], low[child]);
	}
	
	out[node] = timer++;
}

int32_t main()
{
	fastio
	
	int n; cin >> n; // Num of nodes
	int m; cin >> m; // Num of edges
	adj = vector<vector<int>>(n+1, vector<int>(0));
	vis = vector<bool>(n+1, false);
	in = vector<int>(n+1);
	out = vector<int>(n+1);
	low = vector<int>(n+1);
	
	for(int i=0; i<m; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	print_unw(n, m, adj); cout << endl;
	cout << endl << endl;
	
	timer = 1;
	int src = 1;
	dfs_iol(src, 0);
	
	cout << "node\tin\tout\tlow" << endl;
	cout << "----\t--\t---\t---" << endl;
	for(int i=1; i<=n; i++) {
		cout << i << "\t" << in[i] << "\t" << out[i] << "\t" << low[i] << endl;
	}
	
	
	
	return 0;
}