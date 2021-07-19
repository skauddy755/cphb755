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

// Finding the minimum spanning tree

bool comp(Edge e1, Edge e2)
{
	return e1.w < e2.w;
}

void prims(vector<Edge> edges, int n)
{
	int m = edges.size(); cout << m;
	
	vector<bool> nodesUsed(n+1, false);
	vector<bool> edgesUsed(m, false);
	
	edgesUsed[0] = true;
	nodesUsed[edges[0].a] = nodesUsed[edges[0].b] = true;
	
	for(int k=2; k<=n-1; k++)
	{
		cout << "\n" << k;
		for(int i=0; i<m; i++)
		{
			Edge e = edges[i];
			if(edgesUsed[i]) continue;
			bool f1 = nodesUsed[e.a];
			bool f2 = nodesUsed[e.b];
			
			
			bool flag = (f1 && !f2) || (!f1 && f2);
			cout << " " << i << f1 << f2 << flag;
			if(flag)
			{
				nodesUsed[e.a] = true;
				nodesUsed[e.b] = true;
				edgesUsed[i] = true;
				break;
			}
		}
	}
	
	cout << "\nEdges used array\n";
	log1(edgesUsed);
	int sum = 0;
	for(int i=0; i<m; i++) if(edgesUsed[i]) sum += edges[i].w;
	cout << "MinSum = " << sum << endl;
}

int32_t main()
{
	fastio
	
	int n, m;
	cin >> n; // num of nodes
	cin >> m; // num of edges
	
	vector<Edge> edges;
	
	for(int i=0; i<m; i++)
	{
		int a, b, w;
		cin >> a >> b >> w;
		edges.push_back({a, b, w});
	}
	
	printf("\nEdges\n");
	for(auto e : edges) printf("%d--%d : %d\n", e.a, e.b, e.w);
	
	printf("\nEdges after sorting:\n");
	sort(edges.begin(), edges.end(), comp);
	for(auto e : edges) printf("%d--%d : %d\n", e.a, e.b, e.w);
	
	prims(edges, n);
	
	return 0;
}