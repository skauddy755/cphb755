#include <bits/stdc++.h>
using namespace std;

/*

print_unw() : for both unD and D
print_w()   : for both unD and D

gen_AL_unw_und() : print_unw() : Edge List:{ 1 2; 2 3; 2 4; 3 5; 4 5; 4 6 }
gen_AL_unw_d()   : print_unw() : Edge List:{ 1 2; 2 3; 2 4; 3 5; 4 5; 4 6 }
gen_AL_w_und()   : print_w()   : Edge List:{ 1 2 3; 2 3 4; 2 4 1; 3 5 4; 4 5 10; 4 6 5 }
gen_AL_w_d()     : print_w()   : Edge List:{ 1 2 3; 2 3 4; 2 4 1; 3 5 4; 4 5 10; 4 6 5 }

Weighted use   : vector<pair<int,int>> adj[n+1]
Unweighted use : vector<int> adj[n+1]

*/

void print_unw(int n, int m, vector<int> adj[])
{
	for(int i=1; i<=n; i++)
	{
		cout << i;
		for(int child : adj[i])
		{
			cout << " -> " << child;
		}
		cout << "\n";
	}
}
//------------------------------------------------------------------
void print_w(int n, int m, vector<pair<int,int>> adj[])
{
	for(int i=1; i<=n; i++)
	{
		cout << i;
		for(pair<int,int> p : adj[i])
		{
			int child = p.first;
			int w = p.second;
			printf(" -> (%d,%d)", child, w);
		}
		cout << "\n";
	}
}
//==================================================================

// Unweighted, Undirected graph
// Edge List:{ 1 2; 2 3; 2 4; 3 5; 4 5; 4 6 }
void gen_AL_unw_und()
{
	
	int n; cin >> n; // Num of nodes
	int m; cin >> m; // Num of edges
	vector<int> adj[n+1];
	for(int i=0; i<m; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	print_unw(n, m, adj);
}
//------------------------------------------------------------------
// Unweighted, Directed graph
// Edge List:{ 1 2; 2 3; 2 4; 3 5; 4 5; 4 6 }
void gen_AL_unw_d()
{
	
	int n; cin >> n; // Num of nodes
	int m; cin >> m; // Num of edges
	vector<int> adj[n+1];
	for(int i=0; i<m; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
	}
	
	print_unw(n, m, adj);
}
//------------------------------------------------------------------
// Weighted, Undirected graph
// Edge List:{ 1 2 3; 2 3 4; 2 4 1; 3 5 4; 4 5 10; 4 6 5 }
void gen_AL_w_und()
{
	int n; cin >> n; // Num of nodes
	int m; cin >> m; // Num of edges
	vector<pair<int,int>> adj[n+1];
	for(int i=0; i<m; i++)
	{
		int a, b, w;
		cin >> a >> b >> w;
		adj[a].push_back({b, w});
		adj[b].push_back({a, w});
	}
	
	print_w(n, m, adj);
}
//------------------------------------------------------------------
// Weighted, Undirected graph
// Edge List:{ 1 2 3; 2 3 4; 2 4 1; 3 5 4; 4 5 10; 4 6 5 }
void gen_AL_w_d()
{
	int n; cin >> n; // Num of nodes
	int m; cin >> m; // Num of edges
	vector<pair<int,int>> adj[n+1];
	for(int i=0; i<m; i++)
	{
		int a, b, w;
		cin >> a >> b >> w;
		adj[a].push_back({b, w});
	}
	
	print_w(n, m, adj);
}


//===================================================================
//===================================================================

int main()
{
	/*cout << "\n\nUnweighted, Undirected graph:\n";
	gen_AL_unw_und();*/
	
	/*cout << "\n\nUnweighted, Directed graph:\n";
	gen_AL_unw_d();*/
	
	cout << "\n\nWeighted, Undirected graph:\n";
	gen_AL_w_und();
	
	/*cout << "\n\nWeighted, Directed graph:\n";
	gen_AL_w_d();*/
	
	return 0;
}