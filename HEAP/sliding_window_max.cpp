#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
#define log1(a) for(auto x:a)cout << x <<" ";cout <<endl;
#define log2(a,r,c) for(int i=0;i<r;i++){for(int j=0;j<c;j++)cout<<a[i][j]<<" ";cout << endl;}

using namespace std;
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};

class Solution {
	
	private:
	public:
	
	// Time complexity: O(N):
	vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> ans;
        list<int> ds;
        
        int i=0, j=0;
        while(j < n) {
            // include j in calculation:
            while(!ds.empty() && arr[ds.back()] <= arr[j]) ds.pop_back();
            ds.push_back(j);
            
            if(j-i+1 < k) {
                j++;
            }
            else if(j-i+1 == k){
                // extract ans from calculation:
                ans.push_back(arr[ds.front()]);
                
                // remove i from calculation:
                if(ds.front() == i) ds.pop_front();
                
                // slide the window:
                j++;
                i++;
            }
        }
        
        return ans;
    }
    
    // Time Complexity: O(N.log(K)):
    vector<int> maxSlidingWindow_usingMaxHeap(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> ans;
        priority_queue<pair<int,int>> pq;
        
        int i=0, j=0;
        while(j < n) {
            // include j in calculation:
            pq.push({arr[j], j});
            
            if(j-i+1 < k) j++;
            
            else if(j-i+1 == k) {
                // extract ans from calculation:
                while(!pq.empty() && pq.top().second < i) pq.pop();
                ans.push_back(pq.top().first);
                
                // no need to explicitely remove i from calculation:
                
                // slide the window:
                i++;
                j++;
            }
        }
        return ans;
    }
	
};

int main()
{
	// taking inputs:
	// --------------
	vector<int> arr = {1,3,-1,-3,5,3,6,7};
	int k = 3;
	
	// Calling the working function:
	// -----------------------------
	Solution sol;
	log1(sol.maxSlidingWindow(arr, k));
	log1(sol.maxSlidingWindow_usingMaxHeap(arr, k));
	
	return 0;
}