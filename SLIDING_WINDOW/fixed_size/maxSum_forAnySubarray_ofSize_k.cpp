#include<bits/stdc++.h>
#define int long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
#define log1(a) for(auto x:a)cout << x <<" ";cout <<endl;
#define log2(a,r,c) for(int i=0;i<r;i++){for(int j=0;j<c;j++)cout<<a[i][j]<<" ";cout << endl;}

using namespace std;
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};

// Maximum sum of any subarray of size k:
int maxSumForAnySubarray(vector<int> &arr, int k) {
	
	int n = arr.size();
	
	int ans = 0;
    int sum = 0;
    
    int i=0, j=0;
    while(j < n) {
        
        // include j in calculations:
        sum += arr[j];
        
        // if window size less than k, then increase it:
        if(j - i + 1 < k) j++;
        
        // if window size == k, then just maintain it:
        else if(j - i + 1 == k) {
            
            // pull ans from calculations:
            ans = max(ans, sum);
            
            // remove i from calculations:
            sum -= arr[i];
            
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
	
	// Maximum sum of any subarray of size k:
	int ans = maxSumForAnySubarray(arr, k);
	cout << ans << endl;
	return 0;
}

/*

input-1:
-------
4 2
100 200 300 400
output-1:
--------
700

====================================

input-2:
-------
4 4
100 200 300 400
output-2:
--------
1000

*/

