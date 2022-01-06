#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
#define log1(a) for(auto x:a)cout << x <<" ";cout <<endl;
#define log2(a,r,c) for(int i=0;i<r;i++){for(int j=0;j<c;j++)cout<<a[i][j]<<" ";cout << endl;}

using namespace std;
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};

class Solution {
	
	private:
	public:
	
	int paint(int A, int B, vector<int> &arr); // only definition...
};



bool isPossible(int targetTime, int A, vector<int> &arr) {
    int n = arr.size();
    
    int time = 0;
    for(int i=0; i<n; i++) {
        if(A == 0) return false;
        if(arr[i] <= targetTime) {
            if(time + arr[i] <= targetTime) {
                time += arr[i];
            }
            else {
                time = arr[i];
                A--;
            }
        }
        else {
            return false;
        }
    }
    return true;
}

int Solution::paint(int A, int B, vector<int> &arr) {
    int n = arr.size();

    int lo = INT_MIN, hi = 0;
    for(int x : arr) {
        lo = max(lo, x);
        hi += x;
    }

    cout << lo << " " << hi << endl;
    int ans = hi;
    while(lo <= hi) {
        int mid = lo + (hi-lo)/2;
        if(isPossible(mid, A, arr)) {
            ans = mid;
            hi = mid - 1;
        }
        else {
            lo = mid + 1;
        }
    }
    const int M = 1e7+3;
    ans = ((ans % M) * B) % M;
    return ans;
}

int main()
{
	// taking inputs:
	// --------------
	int A, B; cin >> A >> B;
	vector<int> arr;
	int num = 0;
	while (getline(X, T, ' ')) {
        cout << T << endl;
    }
	for(char ch : str) {
		if(ch == ' ') {
			arr.push_back(num);
			num = 0;
		}
		else {
			num = (num*10) + (ch - '0');
		}
	}
	arr.push_back(num);
	cout << A << " " << B << endl;
	cout << str << endl;
	log1(arr);
	
	// Calling the working function:
	// -----------------------------
	Solution sol;
	cout << sol.paint(A, B, arr) << "\n";
	
	return 0;
}