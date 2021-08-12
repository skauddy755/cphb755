#include<bits/stdc++.h>
#define int long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
#define log1(a) for(auto x:a)cout << x <<" ";cout <<endl;
#define log2(a,r,c) for(int i=0;i<r;i++){for(int j=0;j<c;j++)cout<<a[i][j]<<" ";cout << endl;}

using namespace std;
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};

// Longest Substring with no repeating characters:
int longestSubstr_noRepChars(string str) {
	
	int n = str.length();
	if(n == 0) return 0;
        
    unordered_map<char,int> hm;
    int ans = 0;
    
    int i=0, j=0;
    while(j < n) {
        
        // include j in the calculations:
        char kj = str[j];
        if(hm.find(kj) != hm.end()) hm[kj]++;
        else hm[kj] = 1;
        
        // if current value is < required value
        // => size of HM > len of substring being considered:
        // Although this case would never arise
        if(hm.size() > j - i + 1) j++;
        
        // if current value is == required value
        // => val for each key of HM is 1
        // => size of HM == len of substring being considered:
        else if(hm.size() == j - i + 1) {
            // pull ans from calculations:
            ans = max(ans, j - i + 1);
            
            // increase the size of window:
            j++;
        }
        // if current value is > required value
        // => size of HM < len of substring being considered:
        else {
            // remove i from calculations:
            while(!hm.empty() && hm.size() < j - i + 1) {
                char ki = str[i];
                hm[ki]--;
                if(hm[ki] == 0) hm.erase(ki);
                i++;
            }
            j++;
        }
    }
    return ans;
}

int32_t main()
{
	fastio
	string str; cin >> str;
	
	// Longest Substring with no repeating characters:
	int ans = longestSubstr_noRepChars(str);
	cout << ans << endl;
	return 0;
}

/*

input-1:
-------
abcabcbb

output-1:
--------
3

====================================

input-2:
-------
bbbbb

output-2:
--------
1

====================================

input-3:
-------
pwwkew

output-3:
--------
3

*/

