#include<bits/stdc++.h>
#define int long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
#define log1(a) for(auto x:a)cout << x <<" ";cout <<endl;
#define log2(a,r,c) for(int i=0;i<r;i++){for(int j=0;j<c;j++)cout<<a[i][j]<<" ";cout << endl;}

using namespace std;
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};

vector<int> arr;
int n;

// generate all subsets of a given set of numbers in an array:
vector<vector<int>> ans;
vector<int> temp;

void gen_subset_dsc(int index) {
	if(index == n) ans.push_back(temp);
	
	else {
		temp.push_back(arr[index]);
		gen_subset_dsc(index + 1);
		temp.pop_back();
		gen_subset_dsc(index + 1);
	}
}

void gen_subset_asc(int index) {
	if(index == n) ans.push_back(temp);
	
	else {
		gen_subset_asc(index + 1);
		temp.push_back(arr[index]);
		gen_subset_asc(index + 1);
		temp.pop_back();
	}
}

void print_all_subsets() {
	for(auto v : ans) {
		for(int x : v) {
			cout << x << " ";
		}
		cout << endl;
	}
}

int32_t main()
{
	fastio
	
	cin >> n;
	arr = vector<int>(n);
	for(int &x : arr) cin >> x;
	
	ans = vector<vector<int>>();
	temp = vector<int>();
	
	gen_subset_asc(0);
	print_all_subsets();
	
	return 0;
}