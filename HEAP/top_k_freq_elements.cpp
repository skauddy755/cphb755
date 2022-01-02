#include<bits/stdc++.h>
#define int long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
#define log1(a) for(auto x:a)cout << x <<" ";cout <<endl;
#define log2(a,r,c) for(int i=0;i<r;i++){for(int j=0;j<c;j++)cout<<a[i][j]<<" ";cout << endl;}

using namespace std;
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};

vector<int> topKFrequent(vector<int>& arr, int k) {
	int n = arr.size();
    unordered_map<int,int> hm;
    for(int x : arr) {
        if(hm.find(x) != hm.end()) hm[x]++;
        else hm[x] = 1;
    }
        
    priority_queue<pair<int,int>> pq;
    for(auto m : hm) {
        pq.push({m.second, m.first});
    }
        
    vector<int> ans(k);
    for(int i=0; i<k; i++) {
        ans[i] = pq.top().second;
        pq.pop();
    }
    return ans;
}

int32_t main()
{
	fastio
	
	vector<int> arr = {1,1,1,2,2,3};
	int k = 2;
	log1(topKFrequent(arr, k));
	
	return 0;
}