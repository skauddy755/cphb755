#include<bits/stdc++.h>
#define int long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
#define log1(a) for(auto x:a)cout << x <<" ";cout <<endl;
#define log2(a,r,c) for(int i=0;i<r;i++){for(int j=0;j<c;j++)cout<<a[i][j]<<" ";cout << endl;}

using namespace std;
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};

// First -ve integer in every subarrays of size k:
vector<int> firstNegativeForAllSubarray(vector<int> &arr, int k) {
	int n = arr.size();
	queue<int> q; // will only store the index of the probable answers
    vector<int> ans(n - k + 1); // will store the index of the answers
    
    int i=0, j=0;
    while(j < n) {
        
        // include calculation of index j:
        if(arr[j] < 0) q.push(j);
        
        // if window size still less than k, then simply incrase the size:
        if(j - i + 1 < k) j++;
        
        // window size has been hit, then just need to maintain it:
        else if(j - i + 1 == k) {
            
            // pull ans from calculation:
            ans[i] = q.empty() ? -1 : q.front();
            
            // remove calculation of i:
            if(arr[i] < 0 && !q.empty()) q.pop();
            
            // slide the window:
            i++;
            j++;
        }
    }
    
    // Replace the indices with the actual value:
    for(int &x : ans) x = (x == -1) ? 0 : arr[x];
    return ans;
}

int32_t main()
{
	fastio
	int n, k; cin >> n >> k;
	vector<int> arr(n); for(int &x : arr) cin >> x;
	
	// First -ve integer in every subarrays of size k:
	vector<int> ans = firstNegativeForAllSubarray(arr, k);
	for(int x : ans) cout << x << " ";
	cout << endl;
	return 0;
}

/*

Input-1:
-------
5 2
-8 2 3 -6 10
Output-1:
--------
-8 0 -6 -6

================================

Input-2:
-------
8 3
12 -1 -7 8 -15 30 16 28
Output-2:
--------
-1 -1 -7 -15 -15 0 

*/

