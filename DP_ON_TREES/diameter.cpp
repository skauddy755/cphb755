#include<bits/stdc++.h>
#define int long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
#define log1(a) for(auto x:a)cout << x <<" ";cout <<endl;
#define log2(a,r,c) for(int i=0;i<r;i++){for(int j=0;j<c;j++)cout<<a[i][j]<<" ";cout << endl;}

using namespace std;
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};

int n;
vector<vector<int>> tree;
vector<int> downPath;
int ans;

void dfs_downPath(int node, int par) {
	
	downPath[node] = 0;
	for(int child : tree[node]) {
		if(child == par) continue;
		
		dfs_downPath(child, node);
		downPath[node] = max(downPath[node], 1 + downPath[child]);
	}
}

void dfs(int node, int par) {
	
	int mx = 0, nmx = 0;
	for(int child : tree[node]) {
		if(child == par) continue;
		
		dfs(child, node);
		int d = downPath[child] + 1;
		if(d >= mx) {
			nmx = mx;
			mx = d;
		}
		else if(d > nmx) {
			nmx = d;
		}
	}
	
	int diam = mx + nmx;
	
	ans = max(ans, diam);
}

int32_t main()
{
	fastio
	
	int n; cin >> n;
	
	tree = vector<vector<int>>(n+1, vector<int>(0));
	downPath = vector<int>(n+1);
	ans = 0;
	
	for(int i=1; i<n; i++) {
		int a, b; cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	
	dfs_downPath(1, 0);
	dfs(1, 0);
	
	cout << ans << "\n";
	
	return 0;
}