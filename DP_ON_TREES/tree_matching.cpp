#include<bits/stdc++.h>
#define int long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
#define log1(a) for(auto x:a)cout << x <<" ";cout <<endl;
#define log2(a,r,c) for(int i=0;i<r;i++){for(int j=0;j<c;j++)cout<<a[i][j]<<" ";cout << endl;}

using namespace std;
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};

int n;
vector<vector<int>> tree;
vector<pair<int,int>> ans;

void dfs(int node, int par) {
	int ans_without = 0;
	vector<int> pre, suf;
	vector<int> children;
	for(int child : tree[node]) {
		if(child == par) continue;
		
		dfs(child, node);
		
		int ans_child = max(ans[child].first, ans[child].second);
		children.push_back(child);
		ans_without += ans_child;
				
		pre.push_back(ans_child);
		suf.push_back(ans_child);
	}
	
	ans[node].first = ans_without;
	
	int numChild = children.size();
	for(int i=1; i<numChild; i++) pre[i] += pre[i-1];
	for(int i=numChild-2; i>=0; i--) suf[i] += suf[i+1];
	
	int ans_with = 0;
	for(int i=0; i<numChild; i++) {
		int child = children[i];
		
		int part1 = (i-1>=0) ? pre[i-1] : 0;
		int part2 = (i+1<numChild) ? suf[i+1] : 0;
		int ans_child = 1 + part1 + ans[child].first + part2;
		ans_with = max(ans_with, ans_child);
	}
	
	ans[node].second = ans_with;
}

int32_t main()
{
	cin >> n;
	tree = vector<vector<int>>(n+1);
	ans = vector<pair<int,int>>(n+1);
	for(int i=1; i<=n-1; i++) {
		int a, b; cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	
	int root = 1, par = 0;
	dfs(root, par);
	int num = max(ans[root].first, ans[root].second);
	
	// for(auto p : ans) cout << p.first << " " << p.second << endl;
	
	cout << num << "\n";
	
	return 0;
}