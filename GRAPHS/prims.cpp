#include<bits/stdc++.h>
#define int long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
#define log1(a) for(auto x:a)cout << x <<" ";cout <<endl;
#define log2(a,r,c) for(int i=0;i<r;i++){for(int j=0;j<c;j++)cout<<a[i][j]<<" ";cout << endl;}

using namespace std;
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};

int spanningTree(int V, vector<vector<int>> adj[])
{
    int sum = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<bool> done(V);
        
    pq.push({0, 0});
    while(!pq.empty()) {
        int key = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        
        if(done[u]) continue;
        sum += key;
        for(auto edge : adj[u]) {
            int v = edge[0];
            int w = edge[1];
            
            if(!done[v]) pq.push({w, v});
        }
        done[u] = true;
    }
    return sum;
}

int32_t main()
{
	fastio
	
	int V, E; cin >> V >> E;
	vector<vector<int>> adj[V];
	for(int i=1; i<=E; i++) {
		int u, v, w; cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	cout << spanningTree(V, adj);
	
	return 0;
}