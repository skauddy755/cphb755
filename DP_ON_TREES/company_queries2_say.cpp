#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
#define log1(a) for(auto x:a)cerr << x <<" ";cerr <<endl;
#define log2(a,r,c) for(int i=0;i<r;i++){for(int j=0;j<c;j++)cerr<<a[i][j]<<" ";cerr << endl;}

using namespace std;
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};

int n, q;
vector<vector<int>> tree;
int m;
vector<vector<int>> sp;

vector<int> depth;

void print() {
	for(int i=0; i<=n; i++) {
		int node = i;
		cerr << node;
		for(int child : tree[node]) {
			cerr << "- " << child;
		}
		cerr << endl;
	}
}

void genSparse_and_buildTree() {
	
	tree = vector<vector<int>>(n+1, vector<int>(0));
	sp = vector<vector<int>>(n+1, vector<int>(m, 0));
	
	for(int i=2; i<=n; i++) {
		int node = i;
		int par; cin >> par;
		
		tree[par].push_back(node);
		tree[node].push_back(par);
		sp[node][0] = par;
	}
	
	for(int j=1; j<m; j++) {
		for(int i=2; i<=n; i++)
			sp[i][j] = sp[sp[i][j-1]][j-1];
	}
}

void dfs_depth(int node, int par) {
	for(int child : tree[node]) {
		if(child == par) continue;
		
		depth[child] = depth[node] + 1;
		dfs_depth(child, node);
	}
}

int solve() {
	int a, b; cin >> a >> b;
	if(depth[a] < depth[b]){
		swap(a,b);
	}
	int da = depth[a];
	int db = depth[b];
	int diff = da-db;
	
	int up = 0;
	while(diff != 0) {
		int bit = diff & 1;
		if(bit) a = sp[a][up];
		
		up++;
		diff/=2;
	}
	if(a == b) return a;
	for(int k = m-1; k>=0; k--) {
		if(sp[a][k] == sp[b][k]) continue;
		
		a = sp[a][k];
		b = sp[b][k];
	}
	
	return sp[a][0];
}

int main()
{
	fastio;
	
	cin >> n >> q;
	m = 25;
	genSparse_and_buildTree();
	
	depth = vector<int>(n+1);
	dfs_depth(1, 0);
	
	
	while(q--) cout << solve() << "\n";
	
	return 0;
}