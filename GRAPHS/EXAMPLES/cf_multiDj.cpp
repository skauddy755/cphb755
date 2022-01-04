// https://codeforces.com/problemset/problem/1611/E1

#include<bits/stdc++.h>
#define int long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
#define log1(a) for(auto x:a)cout << x <<" ";cout <<endl;
#define log2(a,r,c) for(int i=0;i<r;i++){for(int j=0;j<c;j++)cout<<a[i][j]<<" ";cout << endl;}

using namespace std;
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
const int INF = 1e9+7;

const int myPos = 1;
int n, k;
vector<int> fds;
vector<vector<int>> adj;
vector<int> leaves;

void print_tree() {
	for(int i=1; i<=n; i++) {
		cout << i << "-> ";log1(adj[i]);
	}
	cout << endl;
}

void dijkstra(vector<int> srcs, vector<int> &dist) {
	
	dist = vector<int>(n+1, INF);
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	vector<bool> done(n+1);
	for(int s : srcs) {
		dist[s] = 0;
		pq.push({dist[s], s});
	}
	
	
	while(!pq.empty()) {
		int u = pq.top().second;
		pq.pop();
		
		if(done[u]) continue;
		for(int v : adj[u]) {
			if(!done[v] && dist[u] + 1 < dist[v]) {
				dist[v] = dist[u] + 1;
				pq.push({dist[v], v});
			}
		}
		done[u] = true;
	}
}

bool test_case() {
	cin >> n >> k;
	fds = vector<int>(k);
	for(int &x : fds) cin >> x;
	
	adj = vector<vector<int>>(n+1, vector<int>(0));
	for(int i=1; i<=n-1; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	// find leaves:
	leaves = vector<int>(0);
	for(int i=0; i<=n; i++) {
		int deg = adj[i].size();
		if(i!=myPos && deg == 1) leaves.push_back(i);
	}
	
	
	// multi-src dijkstra:
	vector<int> distMe;
	dijkstra({myPos}, distMe);
	
	// single-src dijkstra:
	vector<int> distFds;
	dijkstra(fds, distFds);
	
	
	// log1(distMe); log1(distFds);
	for(int leaf : leaves) {
		if(distMe[leaf] < distFds[leaf]) return true;
	}
	return false;
}

int32_t main()
{
	fastio
	
	int T; cin >> T;
	for(int t=1; t<=T; t++)
	{
		string ans = test_case() ? "YES" : "NO";
		cout << ans << "\n";
		
		// cout << endl << endl;
	}
	
	return 0;
}