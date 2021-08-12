#include<bits/stdc++.h>
#define int long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
#define log1(a) for(auto x:a)cout << x <<" ";cout <<endl;
#define log2(a,r,c) for(int i=0;i<r;i++){for(int j=0;j<c;j++)cout<<a[i][j]<<" ";cout << endl;}

using namespace std;
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};

// Longest Substring of exactly k distinct (unique) characters:
int longestSubstr(string str, int k) {
	
	int n = str.length();
	int ans	= -1;
	unordered_map<char,int> hm;
	
	int i=0, j=0;
	while(j < n) {
		
		// include j in the calculations:
		if(hm.find(str[j]) != hm.end()) hm[str[j]]++;
		else hm[str[j]] = 1;
		
		// if current value less than required value, increase the window size:
		if(hm.size() < k) j++;
		
		// if current value == required value, pull answer from it:
		else if(hm.size() == k) {
			// Pull answer from calculations:
			ans = max(ans, j - i + 1);
			
			// increase the window size;
			j++;
		}
		
		// if current calue > required value, then decrease the window size:
		else {
			
			while(!hm.empty() && hm.size() > k) {
				char key = str[i];
				hm[key]--;
				if(hm[key] == 0) hm.erase(key);
				i++;
			}
			j++;
		}
		
	}
	
	// generate ANS from start and end:
	return ans;
}

int32_t main()
{
	fastio
	string str; cin >> str;
	int k; cin >> k;
	
	// Longest Substring of exactly k distinct (unique) characters:
	int ans = longestSubstr(str, k);
	cout << ans << endl;
	return 0;
}

/*

input-1:
-------
aabacbebebe
3
output-1:
--------
7

====================================

input-2:
-------
aaaa
2
output-2:
--------
-1

*/

