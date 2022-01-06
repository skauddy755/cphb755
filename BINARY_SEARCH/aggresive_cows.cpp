#include<bits/stdc++.h>
#define int long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
#define log1(a) for(auto x:a)cout << x <<" ";cout <<endl;
#define log2(a,r,c) for(int i=0;i<r;i++){for(int j=0;j<c;j++)cout<<a[i][j]<<" ";cout << endl;}

using namespace std;
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};

bool isPossible(int targetDist, vector<int> &arr, int c) {
	int n = arr.size();
	
	int last = arr[0];
	c--;
	
	for(int i=1; i<n; i++) {
		if(c == 0) {
			break;
		}
		else {
			if(arr[i] - last >= targetDist) {
				last = arr[i];
				c--;
			}
		}
	}
	
	return (c == 0);
}

int test_case() {
	int n, c; cin >> n >> c;
	vector<int> arr(n);
	for(int &x : arr) cin >> x;
	sort(arr.begin(), arr.end());
	
	int lo = 1, hi = arr[n-1] - arr[0];
	
	// 1 1 1 1 1 1 1 0 0 0 0 0 0
	int ans = hi;
	while(lo <= hi) {
		int mid = lo + (hi-lo)/2;
		if(isPossible(mid, arr, c)) {
			ans = mid;
			lo = mid + 1;
		}
		else {
			hi = mid - 1;
		}
	}
	return ans;
}

int32_t main()
{
	fastio
	
	int T; cin >> T;
	for(int t=1; t<=T; t++)
	{
		cout << test_case() << "\n";
	}
	
	return 0;
}