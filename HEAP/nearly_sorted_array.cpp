#include<bits/stdc++.h>
#define int long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
#define log1(a) for(auto x:a)cout << x <<" ";cout <<endl;
#define log2(a,r,c) for(int i=0;i<r;i++){for(int j=0;j<c;j++)cout<<a[i][j]<<" ";cout << endl;}

using namespace std;
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};

// inplace sorting:
// Time Complexity: O(N.log(K))
void easySortAsc_usingMinHeap(vector<int> &arr, int k) {
	int n = arr.size();
	priority_queue<int, vector<int>, greater<int>> pq;
    int i=0, j=0;
    while(j < n) {
        // include j in calculations:
        pq.push(arr[j]);
        
        if(j-i+1 < k) j++;
        
        else if(j-i+1 == k) {
            // extract ans from calculations:
            arr[i] = pq.top();
            
            // remove i from calculations:
            pq.pop();
            
            // slide the window:
            i++;
            j++;
        }
    }
    while(!pq.empty()) arr[i++] = pq.top(), pq.pop();
}

// inplace sorting:
// Time Complexity: O(NK)
void easySortAsc_insertionSort(vector<int> &arr, int k) {
	int n = arr.size();
	
	auto swap = [](int &a, int &b){
		int temp = a;
		a = b;
		b = temp;
	};
	
	for(int i=1; i<n; i++) {
		for(int j=i-1; j >= min(0LL, i-k); j--) {
			if(arr[j] > arr[j+1]) swap(arr[j], arr[j+1]);
			else break;
		}
	}
}

int32_t main()
{
	fastio
	
	vector<int> arr = {2, 6, 3, 12, 56, 8};
	int k = 3;
	
	log1(arr);
	
	easySortAsc_usingMinHeap(arr, k);
	// easySortAsc_insertionSort(arr, k);
	
	log1(arr);
	
	
	return 0;
}