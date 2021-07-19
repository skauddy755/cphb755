#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
#define log1(a) for(auto x:a)cout << x <<" ";cout <<endl;
#define log2(a,r,c) for(int i=0;i<r;i++){for(int j=0;j<c;j++)cout<<a[i][j]<<" ";cout << endl;}

using namespace std;
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};

/*

Example used:
=============
6 9
1 2 9
1 6 6
2 4 2
2 3 14
3 4 9
3 5 1
4 5 10
4 6 11
5 6 15

*/

typedef struct {
	int a;
	int b;
	int w;
} Edge;

struct compare_weights{
	bool operator()(Edge const& e1, Edge const& e2)
	{
	   return e1.w > e2.w;
	}
};

priority_queue<Edge, vector<Edge>, compare_weights> edges;
int n, m;

void ds_union(int a, int b, vector<int> &dsa)
{
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
}

// Finding the minimum spanning tree
void kruskals()
{
	vector<Edge> edgesTaken;
	vector<int> nodes_dsa(n+1, -1);
	
	int k  = 1;
	Edge e1 = edges.top(); edges.pop();
	edgesTaken.push_back(e1);
	ds_union(e1.a, e1.b, nodes_dsa);
	k++;
	
	while(!edges.empty())
	{
		if(k > n-1) break;
		
		Edge e = edges.top(); edges.pop();
		
		edgesTaken.push_back(e);
		ds_union(e.a, e.b, nodes_dsa);
		k++;
	}
	
	for(Edge e : edgesTaken) cout << e.a << " -- " << e.b << " : " << e.w << endl;
	int sum = 0;
	for(Edge e : edgesTaken) sum += e.w;
	cout << "MinSum = " << sum << endl;
}

int32_t main()
{
	
	fastio
	
	cin >> n; // num of nodes
	cin >> m; // num of edges
	
	for(int i=0; i<m; i++)
	{
		int a, b, w;
		cin >> a >> b >> w;
		edges.push({a, b, w});
	}
	
	/*while(!edges.empty())
	{
		Edge e = edges.top();
		cout << e.a << "--" << e.b << " : " << e.w << endl;
		edges.pop();
	}*/
	
	kruskals();
	
	return 0;
}