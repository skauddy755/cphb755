#include<bits/stdc++.h>
#define int long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
#define log1(a) for(auto x:a)cout << x <<" ";cout <<endl;
#define log2(a,r,c) for(int i=0;i<r;i++){for(int j=0;j<c;j++)cout<<a[i][j]<<" ";cout << endl;}

using namespace std;
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};

int n;
vector<vector<int>> tree;
vector<bool> vis;
vector<pair<int,int>> ans;

void dfs(int node, int par) {
	if(vis[node]) return;
	
	for(int child : tree[node]) {
		if(child == par) continue;
		
		dfs(child, node);
	}
	
	int numChild = tree[node].size();
	vector<int> pre(numChild); pre[0] = max(ans[tree[0]]);
	for(int i=1; i<numChild; i++)  pre[i] = max(ans[tree[i]]);
	vector<int> suf(numChild); suf[numChild - 1] = max(ans[tree[numChild - 1]]);
	for(int i=n-2; i>=0; i--) suf[i] = max(ans[tree[i]]);
	
	
}

int32_t main()
{
	fastio
	
	cin >> n; // m = n-1
	tree = vector<vector<int> >(n+1);
	for(int i=1; i<=(n-1); i++) {
		int a, b; cin >> a >> b;
		tree[a].push_back(b);
	}
	
	vis = vector<bool>(n+1, false);
	ans = vector<pair<int,int>>(n+1, {-1, -1});
	return 0;
}