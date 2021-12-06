#include<bits/stdc++.h>
#define int long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
#define log1(a) for(auto x:a)cerr << x <<" ";cerr <<endl;
#define log2(a,r,c) for(int i=0;i<r;i++){for(int j=0;j<c;j++)cout<<a[i][j]<<" ";cout << endl;}

using namespace std;
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};

int n;
vector<vector<int>> tree;
vector<int> depth;
vector<int> ans;

void dfs_depth(int node, int par) {
	int maxDepth = 0;
	for(int child: tree[node]) {
		if(child == par) continue;
		
		dfs_depth(child, node);
		maxDepth = max(maxDepth, 1 + depth[child]);
	}
	depth[node] = maxDepth;
}

void dfs(int node, int par, int par_partial) {
	// cout << node << " " << par << " " << par_partial << endl;
	
	vector<int> pre;
	vector<int> suf;
	
	int m = 0;
	for(int child : tree[node]) {
		if(child == par) continue;
		
		m++;
		pre.push_back(depth[child]);
		suf.push_back(depth[child]);
	}
	
	for(int i=1; i<m; i++) pre[i] = max(pre[i], pre[i-1]);
	for(int i=m-2; i>=0; i--) suf[i] = max(suf[i], suf[i+1]);
	
	// log1(pre); log1(suf); cout << endl;
	
	int index = -1;
	for(int child : tree[node]) {
		if(child == par) continue;
		
		index++;
		int mdl = (index - 1 >= 0) ? pre[index-1] : -1;
		int mdr = (index + 1 < m) ? suf[index+1] : -1;
		
		int node_partial = 1 + max(max(mdl, mdr), par_partial);
		dfs(child, node, node_partial);
	}
	ans[node] = 1 + max(m>=1 ? suf[0] : -1, par_partial);
}

int32_t main()
{
	fastio
	
	cin >> n;
	tree = vector<vector<int> >(n+1);
	depth = vector<int>(n+1);
	ans = vector<int>(n+1);
	for(int i=1; i<n; i++) {
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	
	dfs_depth(1, 0);
	// log1(depth); cerr << endl;
	
	ans[1] = depth[1];
	dfs(1, 0, -1);
	// log1(ans);
	for(int i=1; i<=n; i++) cout << ans[i] << " ";
	cout << "\n";
	return 0;
}