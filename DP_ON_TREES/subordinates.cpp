#include<bits/stdc++.h>
#define int long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
#define log1(a) for(auto x:a)cout << x <<" ";cout <<endl;
#define log2(a,r,c) for(int i=0;i<r;i++){for(int j=0;j<c;j++)cout<<a[i][j]<<" ";cout << endl;}

using namespace std;
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};

int n;
vector<vector<int>> tree;
vector<int> sub;

void dfs(int node, int par) {
	if(sub[node] != -1) return;
	
	sub[node] = 0;
	
	for(int child : tree[node]) {
		if(child == par) continue;
		
		dfs(child, node);
		sub[node] += (1 + sub[child]);
	}
}

int32_t main()
{
	fastio
	
	cin >> n;
	tree = vector<vector<int> >(n+1);
	for(int i=2; i<=n; i++) {
		int par; cin >> par;
		tree[par].push_back(i);
	}
	sub = vector<int>(n+1, -1);
	
	dfs(1, 0);
	
	for(int i=1; i<=n; i++) cout << sub[i] << " ";
	cout << "\n";
	return 0;
}