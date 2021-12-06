#include<bits/stdc++.h>
#define int long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
#define log1(a) for(auto x:a)cout << x <<" ";cout <<endl;
#define log2(a,r,c) for(int i=0;i<r;i++){for(int j=0;j<c;j++)cout<<a[i][j]<<" ";cout << endl;}

using namespace std;
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};

void gen_sparse(vector<vector<int>> &sp, int n, int m) {
	
	for(int j=1; j<m; j++) {
		for(int i=2; i<=n; i++) sp[i][j] = sp[sp[i][j-1]][j-1];
	}
} 

int32_t main()
{
	fastio
	
	int n, q; cin >> n >> q;
	int m = ceil(log(n) / log(2));
	vector<vector<int>> sp(n+1, vector<int>(m, 0));
	
	for(int i=2; i<=n; i++) cin >> sp[i][0];
	gen_sparse(sp, n, m);
	// log2(sp, n+1, m);
	
	while(q--) {
		int node, k; cin >> node >> k;
		int par = node;
		int pv = 0;
		while(k != 0) {
			int bit = k & 1;
			if(bit) par = sp[par][pv];
			
			k >>= 1;
			pv++;
		}
		int ans = (par == 0) ? -1 : par;
		cout << ans << "\n";
	}
	
	return 0;
}