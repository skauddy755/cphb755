#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
#define log1(a) for(auto x:a)cout << x <<" ";cout <<endl;
#define log2(a,r,c) for(int i=0;i<r;i++){for(int j=0;j<c;j++)cout<<a[i][j]<<" ";cout << endl;}

using namespace std;
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
	
	private:
	public:
	
	ListNode* mergeKLists_logK(vector<ListNode*>& lists) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        int k = lists.size();
        for(int i=0; i<k; i++) {
            if(lists[i]) pq.push({lists[i]->val, i});
        }
        
        ListNode* start = new ListNode();
        ListNode* top = start;
        while(!pq.empty()) {
            int key = pq.top().first;
            int linkId = pq.top().second;
            pq.pop();
            
            top->next = lists[linkId];
            top = top->next;
            
            lists[linkId] = lists[linkId]->next;
            if(lists[linkId]) pq.push({lists[linkId]->val, linkId});
        }
        return start->next;
    }
    
    ListNode* mergeKLists_logN(vector<ListNode*>& A) {
        priority_queue<int> q;
        for(ListNode* start : A) {
            while(start != NULL) {
                q.push(start->val);
                start = start->next;
            }
        }

        ListNode* start = new ListNode(0);
        while(!q.empty()) {
            ListNode* node = new ListNode(q.top());
            q.pop();

            node->next = start->next;
            start->next = node;
        }
        return start->next;
    }
	
};



int main()
{
	// taking inputs:
	// --------------
	vector<vector<int>> mat = {{1,4,5},{1,3,4},{2,6}};
	
	// manipulate inputs:
	//-------------------
	vector<ListNode*> lists;
	for(auto row : mat) {
		ListNode* start = new ListNode();
		ListNode* top = start;
		for(int x : row) {
			ListNode* curr = new ListNode(x);
			top->next = curr;
			top = top->next;
		}
		lists.push_back(start->next);
	}
	
	// Calling the working function:
	// -----------------------------
	Solution sol;
	
	ListNode* head = sol.mergeKLists_logK(lists);
	// ListNode* head = sol.mergeKLists_logN(lists);
	
	// manipulate outputs:
	//--------------------
	vector<int> ans;
	while(head != NULL) {
		ans.push_back(head->val);
		head = head->next;
	}
	log1(ans);
	
	return 0;
}