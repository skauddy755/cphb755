#include<bits/stdc++.h>
#define int long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
#define log1(a) for(auto x:a)cout << x <<" ";cout <<endl;
#define log2(a,r,c) for(int i=0;i<r;i++){for(int j=0;j<c;j++)cout<<a[i][j]<<" ";cout << endl;}

using namespace std;
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};

const int root = 1;
int n, k;
vector<vector<int>> tree;
vector<int> par;
vector<vector<int>> down, ans;

dfs_par(int node) {
	for(int child : tree[node]) {
		if(child == par[node]) continue;
		par[child] = node;
	}
}

dfs_down(int node, int d) {
	if(d == 0) return down[node][d] = 1;
	
	down[node][d] = 0;
	for(int child : node) {
		if(child == par[node]) continue;
		down[node][d] += down[child][d-1];
	}
	
	for(int x=d-1; x>=0; x--) {
		dfs_down()
	}
}

int32_t main()
{
	fastio
	
	cin >> n >> k;
	tree = vector<vector<int>>(n+1);
	par = vector<int>(n+1);
	
	for(int i=1; i<n; i++) {
		int a, b; cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	
	down = vector<vector<int>>(n+1, vector<int>(k+1, -1));
	ans = vector<vector<int>>(n+1, vector<int>(k+1, -1));
	
	dfs_par(root);
	return 0;
}