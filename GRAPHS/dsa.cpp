#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define log1(a) for(auto x:a)cout << x <<" ";cout <<endl;
#define log2(a,r,c) for(int i=0;i<r;i++){for(int j=0;j<c;j++)cout<<a[i][j]<<" ";cout << endl;}

using namespace std;
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};

void ds_union(int a, int b, vector<int> &dsa)
{
	cout << a << " " << b << endl;
	while(dsa[a] > 0) a = dsa[a];
	while(dsa[b] > 0) b = dsa[b];
	
	if(a == b) return;
	if(dsa[a] > dsa[b])
	{
		int temp = a;
		a = b;
		b = temp;
	}
	dsa[a] += dsa[b];
	dsa[b] = a;
	log1(dsa);
}

int ds_find(int node, vector<int> dsa)
{
	if(dsa[node] < 0) return node;
	return ds_find(dsa[node], dsa);
}

int ds_find_pc(int node, vector<int> &dsa)
{
	if(dsa[node] < 0) return node;
	return dsa[node] = ds_find_pc(dsa[node], dsa);
}

int32_t main()
{
	fastio
	
	int n, m;
	cin >> n >> m;
	
	vector<int> dsa(n+1, -1);
	
	for(int i=1; i<m; i++)
	{
		int a, b;
		cin >> a >> b;
		ds_union(a, b, dsa);
	}
	
	cout << endl;
	cout << ds_find(1, dsa) << endl;
	cout << ds_find(2, dsa) << endl;
	cout << ds_find(3, dsa) << endl;
	cout << ds_find(4, dsa) << endl;
	cout << ds_find(5, dsa) << endl;
	cout << ds_find(6, dsa) << endl;
	cout << ds_find(7, dsa) << endl;
	cout << ds_find(8, dsa) << endl;
	
	
	cout << ds_find_pc(4, dsa) << endl;
	cout << ds_find_pc(6, dsa) << endl;
	cout << ds_find_pc(8, dsa) << endl;
	
	log1(dsa);
	
	
	
	return 0;
}