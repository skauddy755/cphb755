#include<bits/stdc++.h>
#define int long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
#define log1(a) for(auto x:a)cout << x <<" ";cout <<endl;
#define log2(a,r,c) for(int i=0;i<r;i++){for(int j=0;j<c;j++)cout<<a[i][j]<<" ";cout << endl;}

using namespace std;
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};

int n;
vector<vector<int>> tree;
vector<int> num;
vector<int> ds;
vector<int> ans;

void dfs_num_ds(int node, int par) {
	
	for(int child : tree[node]) {
		if(child == par) continue;
		
		dfs_num_ds(child, node);
		num[node] += (1 + num[child]);
		ds[node] += (1 + ds[child] + num[child]);
	}
}

void dfs(int node, int par) {
	
	if(node == 1)
		ans[node] = ds[node];
	else 
		ans[node] = ans[par] + (n-1) - (2 * num[node]) - 1;
	
	for(int child : tree[node]) {
		if(child == par) continue;
		
		dfs(child, node);
	}	
}

int32_t main()
{
	cin >> n;
	tree = vector<vector<int>>(n+1);
	num = vector<int>(n+1);
	ds = vector<int>(n+1);
	ans = vector<int>(n+1);
	
	for(int i=1; i<n; i++) {
		int a, b; cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	
	dfs_num_ds(1, 0);
	dfs(1, 0);
	// log1(num);
	// log1(ds);
	// log1(ans);
	
	for(int i=1; i<=n; i++) cout << ans[i] << " ";
	
	return 0;
}