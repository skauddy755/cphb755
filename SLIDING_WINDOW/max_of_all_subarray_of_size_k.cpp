#include<bits/stdc++.h>
#define int long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
#define log1(a) for(auto x:a)cout << x <<" ";cout <<endl;
#define log2(a,r,c) for(int i=0;i<r;i++){for(int j=0;j<c;j++)cout<<a[i][j]<<" ";cout << endl;}

using namespace std;
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};

// Maximum of all subarrays of size k:
vector<int> maxForAllSubarray(vector<int> &A, int k) {
	
	int  n = A.size();
	vector<int> ans(n-k+1); // Actually, (((n-1) - k + 1) + 1)
    list<int> mx; // will store the index of the best (monotonically increasing wrt best)
    
    int i=0, j=0;
    while(j < n) {

        // calculate for index j:
    	while(!mx.empty() && A[mx.back()] <= A[j]) mx.pop_back();
        mx.push_back(j);
    
        // if size of window less than k, then just increase it:
        if(j - i + 1 < k) j++;
    
        // if size of window == k, then maintain it:
        else if(j - i + 1 == k) {
            // pull ans from calculations:
            ans[i] = A[mx.front()];

            // remove the calculation of index i:
            if(mx.front() == i) mx.pop_front();

            // slide the window:
            i++;
            j++;
        }
    }
    return ans;	
}

int32_t main()
{
	fastio
	int n, k; cin >> n >> k;
	vector<int> arr(n); for(int &x : arr) cin >> x;
	
	// Maximum of all subarrays of size k:
	vector<int> ans = maxForAllSubarray(arr, k);
	for(int x : ans) cout << x << " ";
	cout << endl;
	return 0;
}

/*

input-1:
-------
9 3
1 2 3 1 4 5 2 3 6
output-1:
--------
3 3 4 5 5 5 6 

====================================

input-2:
-------
10 4
8 5 10 7 9 4 15 12 90 13
output-2:
--------
10 10 10 15 15 90 90

*/

