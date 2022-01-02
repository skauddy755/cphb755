#include<bits/stdc++.h>
#define int long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
#define log1(a) for(auto x:a)cout << x <<" ";cout <<endl;
#define log2(a,r,c) for(int i=0;i<r;i++){for(int j=0;j<c;j++)cout<<a[i][j]<<" ";cout << endl;}

using namespace std;
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
const int INF = 1e9 + 7;

vector <int> dijkstra_usingMinHeap(int V, vector<vector<int>> adj[], int src)
{
    vector<int> dist(V, INF);
    dist[src] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({dist[src], src});
        
    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
            
        for(auto edge : adj[u]) {
            int v = edge[0];
            int w = edge[1];
                
            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

/*

OPTIMISATIONS:
==============

Problem-(1):
------------
	once u has been processed (used it to relax its neighbours v),
	then also it might again be relaxed by some other vertix,
	which again puts it in the pq;
		
	Optimization:
		we can keep a flag of 'done' to mark it after its adj list has been traversed;
		and before actually traversing, we will check if the node is !done;
		

Problem-(2):
------------
	we are not updating the {dist[v], v}
	instead we are adding a new copy of it
		
	Optimization:
		[{(wrong)}]:
			we can add a label of 'outdated' on the old copy that is still present in the pq
		[{(right)}]:
			we can make use of the 1st Opt.
			Note: the outdated pairs will be of more key than the updated ones
			Hence,
			1. as long as the updated pairs of the same node is present in the pq,
			   outdated ones would never get a chance to come to the top of the pq,
            2. the updated ones will be gone if the node corresponding to it is marked as 'done'
               Well, in that case the outdated ones can come to the top,
			   But, we can immediately just pop them out and not traverse the adj list at all
			   How will we know? LoL!! updated/outdated all have the same corresponding node...
		       So, just before traversing the adj list, we can just check whether the node is !DONE.

*/



// =========================== OPTIMIZED CODE ==========================================

vector <int> dijkstra_usingMinHeap_furtherOpt(int V, vector<vector<int>> adj[], int src)
{
    vector<int> dist(V, INF);
    vector<bool> done(V);
    dist[src] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({dist[src], src});
        
    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        
		if(done[u]) continue;
        for(auto edge : adj[u]) {
            int v = edge[0];
            int w = edge[1];
                
            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
		done[u] = true;
    }
    return dist;
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
	int src; cin >> src;
	
	log1(dijkstra_usingMinHeap(V, adj, src));
	log1(dijkstra_usingMinHeap_furtherOpt(V, adj, src));
	
	return 0;
}
/*
example:
3 3
0 1 1
0 2 6
1 2 3
2
output:
4 3 0 
*/
			     