#include<bits/stdc++.h>
#define int long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
#define log1(a) for(auto x:a)cout << x <<" ";cout <<endl;
#define log2(a,r,c) for(int i=0;i<r;i++){for(int j=0;j<c;j++)cout<<a[i][j]<<" ";cout << endl;}

using namespace std;
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};

int findKthLargest(vector<int>& arr, int k) {
    int n = arr.size();
        
    priority_queue<int> pq;
    for(int x : arr) pq.push(x);
        
    for(int i=1; i<k; i++) {
        pq.pop();
    }
    return pq.top();
}

int32_t main()
{
	fastio
	
	vector<int> arr = {3,2,1,5,6,4};
	int k = 2;
	cout << findKthLargest(arr, k);
	
	return 0;
}