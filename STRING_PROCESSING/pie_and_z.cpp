#include<bits/stdc++.h>
#define int long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
#define log1(a) for(auto x:a)cout << x <<" ";cout <<endl;
#define log2(a,r,c) for(int i=0;i<r;i++){for(int j=0;j<c;j++)cout<<a[i][j]<<" ";cout << endl;}

using namespace std;
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};

string str;
vector<int> pie;


void findPieValue_recursive(int i, int j, vector<int> &pie) {
	if(str[j] == str[i]) pie[i] = j + 1;
	
	else {
		if(j == 0) pie[i] = 0;
		else {
			int k = pie[j-1];
			j = k;
			findPieValue_recursive(i, j, pie);
		}
	}
}

vector<int> genPie_recursive(string str) {
	int n = str.length();
	vector<int> pie(n, 0);
	
	for(int i=1; i<n; i++)
		findPieValue_recursive(i, pie[i-1], pie);
	
	return pie;
}

//================================================================
//================================================================

vector<int> genPie(string str) {
	
	int n = str.length();
	
	vector<int> pie(n, 0);
	for(int i=1; i<n; i++) {
		int j = pie[i-1];
		while(j != 0 && str[j] != str[i])
			j = pie[j-1];
		
		pie[i] = (str[j] == str[i])
			   ? j+1
			   : j;
	}
	
	return pie;
}

vector<int> genZ(string str) {
	
	int n = str.length();
	
	vector<int> z(n, 0);
	int L = 0, R = 0;
	for(int i=1; i<n; i++) {
		
		// set initial value to z[i]:
		if(i <= R)
			z[i] = min(R - i + 1, z[i - L]);
		
		// scan the unscanned part (beyond r):
		while(i+z[i] < n && str[z[i]] == str[i + z[i]])
			z[i]++;
		
		// if scanning at i increases the scanned area,
		// then update the bounds:
		int r_new = i + z[i] - 1;
		if(r_new > R) L = i, R = r_new;
	}
	
	return z;
}

int32_t main()
{
	fastio
	
	cin >> str;
	
	
	cout << "Pie array" << endl;
	log1(genPie_recursive(str));
	log1(genPie(str));
	
	cout << "\nZ array" << endl;
	log1(genZ(str));
	
	
	
	return 0;
}

/*

input-1:
aaaaa
output-1:
Pie array
0 1 2 3 4 
0 1 2 3 4 

Z array
0 4 3 2 1

-------------------------------

input-2:
aaabaab
output-2:
Pie array
0 1 2 0 1 2 0 
0 1 2 0 1 2 0 

Z array
0 2 1 0 2 1 0

-------------------------------

input-3:
abacaba
output-3:
Pie array
0 0 1 0 1 2 3 
0 0 1 0 1 2 3 

Z array
0 0 1 0 3 0 1


*/