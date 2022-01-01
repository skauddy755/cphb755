#include<bits/stdc++.h>
#define int long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
#define log1(a) for(auto x:a)cout << x <<" ";cout <<endl;
#define log2(a,r,c) for(int i=0;i<r;i++){for(int j=0;j<c;j++)cout<<a[i][j]<<" ";cout << endl;}

using namespace std;
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
const int INF = 1e9+7;
// implementing heap using ann array:
/*
	if zero based indexed:
	given, arr[i]: lChild = arr[2*i + 1],
				   rChild = arr[2*i + 2]
				   
	given, arr[i]: par = arr[ceil(i/2) - 1]
	
	if height = H:
		h(root) = 0,
		h(bottommost leaf) = H;
		
		max. number of nodes at height 'h' = 2^h
		max. number of leaves = 2^H
		max. number of node in the tree = 1 + 2^1 + 2^2 + 2^3 + ... + 2^H
										= 2^(H+1) - 1
	
		number of internal nodes (but be aware)
					= (number of nodes in tree) - (number of leaves)
	     			= (2^(H+1) - 1) - 2^H
					= 2^H - 1
					[
						this can also be viewed as:
		 		 			1. number of nodes in a PERFECT BINARY TREE upto height H-1
					 		2. number of leaves - 1 (only if max no of leaves are present)
		     		]
		
		Actual number of nodes in the tree, N
				= 1 + 2^1 + 2^2 + 2^3 + ... + 2^(H-1) + L
				= (2^H - 1) + L
				where, L = actual number of leaves
				and, 1 <= L <= 2^H
			Hence, N = (2^H - 1) + L
			       where, 2^H <= N <= 2^(H+1) - 1
			Hence, H = floor(log2(N))
			
		
		In 0-based indexing:
		--------------------
			I = no. of internal nodes = 2^H - 1 = floor(N/2)
			L = no. of leaves
			N = total number of nodes = I + L
			
			Range of internal nodes: 0 <= i <= I-1
			Range of leaf nodes    : I <= i <= N-1
				
*/

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

void heapify_max(int index, vector<int> &arr, int len) {
	int left = 2*index + 1;
	int right = 2*index + 2;
	
	int largest = index;
	if(left < len && arr[left] > arr[largest]) largest = left;
	if(right < len && arr[right] > arr[largest]) largest = right;
	
	if(largest != index) {
		swap(arr[largest], arr[index]);
		heapify_max(largest, arr, len);
	}
}

void buildHeap_max(vector<int> &arr, int len) {
	for(int i=len-1; i>=0; i--) {
		heapify_max(i, arr, len);
	}
}

void percolateUp_max(int index, vector<int> &arr, int len) {
	int par = ceil(index/2.0) - 1;
	if(par != -1 && arr[par] < arr[index]) {
		swap(arr[par], arr[index]);
		percolateUp_max(par, arr, len);
	}
	
}

void push_max(int key, vector<int> &arr, int &len) {
	if(len == (int)arr.size()) return;
	
	arr[len++] = key;
	percolateUp_max(len-1, arr, len);
	len++;
}

int pop_max(vector<int> &arr, int &len) {
	if(len == 0) return INF;
	
	int val_max = arr[0];
	len--;
	swap(arr[0], arr[len]);
	heapify_max(0, arr, len);
	
	return val_max;
}

int top_max(vector<int> &arr, int len) {
	if(len == 0) return INF;
	return arr[0];
}

void increaseKey_max(int index, int term, vector<int> &arr, int len) {
	arr[index] += term;
	percolateUp_max(index, arr, len);
}

void decreaseKey_max(int index, int term, vector<int> &arr, int len) {
	arr[index] -= term;
	heapify_max(index, arr, len);
}

void heapsort_asc(vector<int> &A) {
	int n = A.size();
	buildHeap_max(A, n);
	for(int i=0; i<n; i++) {
		int len = n - i;
		pop_max(A, len);
	}	
}

int32_t main()
{
	fastio
	
	vector<int> arr = {3, 4, 6, 10, 1, -34, 100, 0, 0, 0, 0, 0, 0, 0, 0};
	int len = 7;
	log1(arr);
	buildHeap_max(arr, len);
	log1(arr);
	
	// pop_max(arr, len);
	// log1(arr);
	// pop_max(arr, len);
	// log1(arr);
	// pop_max(arr, len);
	// log1(arr);
	// pop_max(arr, len);
	// log1(arr);
	
	decreaseKey_max(2, 38, arr, len);
	log1(arr);
	
	cout << endl << endl;
	
	vector<int> A = {5, 100, -23, 1009, -400, 0, 4};
	heapsort_asc(A);
	log1(A);
	return 0;
}