#include<bits/stdc++.h>
#define int long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
#define log1(a) for(auto x:a)cout << x <<" ";cout <<endl;
#define log2(a,r,c) for(int i=0;i<r;i++){for(int j=0;j<c;j++)cout<<a[i][j]<<" ";cout << endl;}

using namespace std;
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};

// Count occurrences of anagrams of p in s:

bool areAllZeros(unordered_map<char,int> &hm) {
    for(auto itr = hm.begin(); itr != hm.end(); itr++) {
        if(itr->second != 0) return false;
    }
    return true;
}

int countAnagrams_v1(string txt, string pat) {
	
	int n = txt.length();
	int k = pat.length();
	    
	unordered_map<char,int> hm;
	// populate the map:
	for(char ch : pat) {
	    if(hm.find(ch) != hm.end()) hm[ch]++;
	    else hm[ch] = 1;
	}
	
	int ans = 0;
	int i = 0, j = 0;
	while(j < n) {
	    
	    // include j in the calculation:
	    if(hm.find(txt[j]) != hm.end()) hm[txt[j]]--;
	    
	    // if window small than k, then just increase the size:
	    if(j-i+1 < k) j++;
	    
	    // if window size == k then, maintain it:
	    else if(j-i+1 == k) {
	        
	        // pull ans from calculations:
	        if(areAllZeros(hm)) ans++;
	        
	        // remove calculations of i:
	        if(hm.find(txt[i]) != hm.end()) hm[txt[i]]++;
	        
	        // slide the window:
	        i++;
	        j++;
	    }
	    
	}
	return ans;
}



int countAnagrams_v2(string txt, string pat) {
	
	int n = txt.length();
	int k = pat.length();
	    
	unordered_map<char,int> hm;
	// populate the map:
	for(char ch : pat) {
	    if(hm.find(ch) != hm.end()) hm[ch]++;
	    else hm[ch] = 1;
	}
	
	int unique = hm.size();
	
	
	int ans = 0;
	int i = 0, j = 0;
	while(j < n) {
	    
	    // include j in the calculation:
	    if(hm.find(txt[j]) != hm.end())
	    {
	        hm[txt[j]]--;
	        int freqAfterInclu = hm[txt[j]];
	        if(freqAfterInclu == 0) unique--;
	        else if(freqAfterInclu == -1) unique++;
	    }
	    
	    // if window small than k, then just increase the size:
	    if(j-i+1 < k) j++;
	    
	    // if window size == k then, maintain it:
	    else if(j-i+1 == k) {
	        
	        // pull ans from calculations:
	        if(unique == 0) ans++;
	        
	        // remove calculations of i:
	        if(hm.find(txt[i]) != hm.end())
	        {
                hm[txt[i]]++;
                int freqAfterExclu = hm[txt[i]];
                if(freqAfterExclu == 0) unique--;
                else if(freqAfterExclu == +1) unique++;
	        }
	        
	        
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
	string txt, pat;
	cin >> txt >> pat;
	
	// Count occurrences of anagrams of p in s:
	int ans1 = countAnagrams_v1(txt, pat); // manually iterating through the hm
	int ans2 = countAnagrams_v2(txt, pat); // smartly keeping a variable 'unique'
	cout << ans1 << " " << ans2 << endl;
}

/*

Example-1:
---------
txt = forxxorfxdofr
pat = for
Output: 3
Explanation: for, orf and ofr appears
in the txt, hence answer is 3.

====================================

Example-2:
---------
txt = aabaabaa
pat = aaba
Output: 4
Explanation: aaba is present 4 times
in txt.

*/

