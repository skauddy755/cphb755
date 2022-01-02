#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
#define log1(a) for(auto x:a)cout << x <<" ";cout <<endl;
#define log2(a,r,c) for(int i=0;i<r;i++){for(int j=0;j<c;j++)cout<<a[i][j]<<" ";cout << endl;}

using namespace std;
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};

struct Node {
	int data;
	Node* left;
	Node* right;
	
	Node(int x) {
		data = x;
		left = NULL;
		right = NULL;
	}
};

class Solution {
	
	private:
	public:
	
	int search(int key, int start, int end, int in[]) {
        int index;
        for(index = start; index <= end; index++) {
            if(in[index] == key) break;
        }
        return index;
    }
    
    Node* genTree(int sIn, int eIn, int sPs, int ePs, int in[], int post[], int n) {
        
        if(sIn > eIn) return NULL;
    
	    int key = post[ePs];
	    int idx = search(key, sIn, eIn, in);
	        
	    int nL = idx - sIn;
	    int nR = eIn - idx;
	        
	    Node* node = new Node(key);
	    node->left = genTree(sIn, idx-1, sPs, ePs-nR-1, in, post, n);
	    node->right = genTree(idx+1, eIn, ePs-nR, ePs-1, in, post, n);
	        
	    return node;
    }
    
    Node* buildTree(int in[],int post[], int n)
    {
        return genTree(0, n-1, 0, n-1, in, post, n);
    }
};

void genPre(Node* node, vector<int> &pre) {
	if(node == NULL) return;
	pre.push_back(node->data);
	genPre(node->left, pre);
	genPre(node->right, pre);
}

int main()
{
	// taking inputs:
	// --------------
	int n; cin >> n;
	int in[n], post[n];
	for(int i=0; i<n; i++) cin >> in[i];
	for(int i=0; i<n; i++) cin >> post[i];
	
	
	// Calling the working function:
	// -----------------------------
	Solution sol;
	Node* root = sol.buildTree(in, post, n);
	
	// gen postOrder:
	vector<int> pre;
	genPre(root, pre);
	log1(pre);
	
	return 0;
}