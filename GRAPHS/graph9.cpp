#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
#define log1(a) for(auto x:a)cout << x <<" ";cout <<endl;
#define log2(a,r,c) for(int i=0;i<r;i++){for(int j=0;j<c;j++)cout<<a[i][j]<<" ";cout << endl;}
#define INF 1e9

using namespace std;
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};

typedef struct {
	int u;
	int v;
	int w;
} Edge;

/*

Example used (dijktras)
-----------------------
6 9
1 2 4
1 6 2
2 3 5
2 6 1
3 4 6
3 5 3
3 6 8
4 5 5
5 6 10

Example used (bellman ford)
---------------------------
6 9
1 2 4
1 6 2
2 3 5
2 6 1
3 4 6
3 5 3
3 6 8
4 5 5
5 6 10

*/

void print_w(int n, int m, vector<vector<pair<int,int>>> adj)
{
	for(int i=1; i<=n; i++)
	{
		cout << i;
		for(pair<int,int> p : adj[i])
		{
			int child = p.first;
			int w = p.second;
			cout << " -> (" << child << "," << w << ")";
		}
		cout << "\n";
	}
}

vector<int> dijsktras(int src, vector<vector<pair<int,int>>> adj)
{
	int n = adj.size() - 1;
	vector<int> dist(n+1, INF);
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	
	dist[src] = 0;
	pq.push({dist[src], src});
	
	while(!pq.empty())
	{
		int node = pq.top().second;
		int d = pq.top().first;
		pq.pop();
		
		for(auto p : adj[node])
		{
			int child = p.first;
			int w = p.second;
			
			if(d + w < dist[child])
			{
				dist[child] = d + w;
				pq.push({dist[child], child});
			}
		}
	}
	
	return dist;
}

vector<int> bellmanford(int src, vector<Edge> edges, int n)
{
	vector<int> dist(n+1, INF);
	dist[src] = 0;
	
	for(int i=1; i<=n-1; i++)
	{
		for(auto e : edges)
		{
			dist[e.v] = min( dist[e.v] , dist[e.u] + e.w );
		}
	}
	
	return dist;
}

int32_t main()
{
	fastio
	
	int n; // Num of nodes
	int m; // Num of edges
	cin >> n >> m;
	vector<vector<pair<int,int>>> adj(n+1, vector<pair<int,int>>(0));
	vector<Edge> edges;
	for(int i=0; i<m; i++)
	{
		int a, b, w;
		cin >> a >> b >> w;
		adj[a].push_back({b, w});
		adj[b].push_back({a, w});
		
		// note: graph is undirected, so also including a reverse edge.
		edges.push_back({a, b, w});
		edges.push_back({b, a, w});
	}
	print_w(n, m, adj);
	cout << "\nEdge List:\n";
	for(auto e : edges) cout << e.u << " " << e.v << " " << e.w << endl;
	
	int src = 1;
	
	// Dijsktras Algorithm:
	cout << "\nDijsktras Algorithm:";
	cout << "\n-----------------------------------\n";
	log1(dijsktras(src, adj));
	cout << "\n===================================\n";
	
	
	
	// Bellman-Ford Algorithm:
	cout << "\nBellman-Ford Algorithm:";
	cout << "\n-----------------------------------\n";
	log1(bellmanford(src, edges, n));
	cout << "\n===================================\n";
	
	
	
	return 0;
}