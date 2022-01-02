#include<bits/stdc++.h>
#define int long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
#define log1(a) for(auto x:a)cout << x <<" ";cout <<endl;
#define log2(a,r,c) for(int i=0;i<r;i++){for(int j=0;j<c;j++)cout<<a[i][j]<<" ";cout << endl;}

using namespace std;
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};

int lastStoneWeight(vector<int>& stones) {
    priority_queue<int> pq;
    for(int x : stones) pq.push(x);
        
    while((int)pq.size() > 1) {
        int x = pq.top(); pq.pop();
        int y = pq.top(); pq.pop();
            
        if(x != y) pq.push(abs(y-x));
    }
        
    if(!pq.empty()) return pq.top();
    return 0;
}

int32_t main()
{
	fastio
	
	vector<int> stones = {2,7,4,1,8,1};
	cout << lastStoneWeight(stones);
	
	return 0;
}