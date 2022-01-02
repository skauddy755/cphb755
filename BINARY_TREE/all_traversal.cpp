#include<bits/stdc++.h>
#define int long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
#define log1(a) for(auto x:a)cout << x <<" ";cout <<endl;
#define log2(a,r,c) for(int i=0;i<r;i++){for(int j=0;j<c;j++)cout<<a[i][j]<<" ";cout << endl;}

using namespace std;
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};


struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	
	TreeNode(int x) {
		val = x;
		left = NULL;
		right = NULL;
	}
};

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> pre;
    if(root == NULL) return pre;

    stack<TreeNode*> s;
    s.push(root);

    while(!s.empty()) {
        TreeNode* curr = s.top();
        pre.push_back(curr->val);
        s.pop();

        if(curr->right) s.push(curr->right);
        if(curr->left) s.push(curr->left);    
    }
    return pre;
}

vector<int> inorderTraversal(TreeNode* root) {
        
    vector<int> in;
        
    TreeNode* curr = root;
    stack<TreeNode*> s;
    while(true) {
        while(curr) {
            s.push(curr);
            curr = curr->left;
        }
        
        if(s.empty()) break;
        TreeNode* par = s.top();
        s.pop();
        
        in.push_back(par->val);
        curr = par->right;
    }
    
    return in;
}

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> post;
    if(root == NULL) return post;
    stack<TreeNode*> s;
    s.push(root);
        
    while(!s.empty()) {
        TreeNode* node = s.top();
        s.pop();
        post.push_back(node->val);
            
        if(node->left) s.push(node->left);
        if(node->right) s.push(node->right);
    }
    reverse(post.begin(), post.end());
    return post;
}

void allOrder_traversal(TreeNode* root) {
	
	vector<int> pre, in, post;
	
    stack<pair<TreeNode*,int>> s;
    if(root) s.push({root, 1});

    while(!s.empty()) {
        auto &p = s.top();
        TreeNode* node = p.first;
        int &state = p.second;

        if(state == 1) {
            pre.push_back(node->val);
            if(node->left) s.push({node->left, 1});
            state++;
        }
        else if(state == 2) {
            in.push_back(node->val);
            if(node->right) s.push({node->right, 1});
            state++;
        }
        else {
            post.push_back(node->val);
            s.pop();
        }
    }
}

int32_t main()
{
	fastio
	
	/*
	for testing refer to:
	---------------------
	
	PREORDER:
	https://leetcode.com/problems/binary-tree-preorder-traversal/
	
	INORDER:
	https://leetcode.com/problems/binary-tree-inorder-traversal/
	
	POSTORDER:
	https://leetcode.com/problems/binary-tree-postorder-traversal/
	
	*/
	
	return 0;
}