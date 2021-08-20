#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
#define log1(a) for(auto x:a)cout << x <<" ";cout <<endl;
#define log2(a,r,c) for(int i=0;i<r;i++){for(int j=0;j<c;j++)cout<<a[i][j]<<" ";cout << endl;}

using namespace std;
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	
	private:
	public:
	
	ListNode* list_start = NULL;
	ListNode* list_end = NULL;
	
	void insert(int data) {
		
		if(list_start == NULL) {	
			list_start = new ListNode(data);
			list_end = list_start;
		}
		
		else {
			list_end->next = new ListNode(data);
			list_end = list_end->next;
		}
	}
	
	void traverse(ListNode* start) {
		if(start == NULL) return;
		
		ListNode* curr = start;
		while(curr != NULL) {
			cout << curr->val << " ";
			curr = curr->next;
		}
	}
	
	pair<ListNode*,ListNode*> reverse(ListNode* A, int k); // only definition...
};

void helperFunction1() {
	cout << "i am helper 1" << endl;
}
void helperFunction2() {
	cout << "i am helper 2" << endl;
}

pair<ListNode*,ListNode*> Solution::reverse(ListNode* A, int k) {
	
	ListNode* start = new ListNode(0);
	start->next = A;
	
	ListNode* par = start;
	ListNode* top = start->next;
	
	int index = 1;
	while(top != NULL && index <= k) {
		ListNode* link = top->next;
		top->next = par;
		
		par = top;
		top = link;
		index++;
	}
	
	A->next = top;
	return {par, top};
}

int main()
{
	// taking inputs:
	// --------------
	int n; cin >> n;
	
	// Calling the working function:
	// -----------------------------
	Solution sol;
	while(n--) {
		int data; cin >> data;
		sol.insert(data);
	}
	
	sol.traverse(sol.list_start);
	ListNode* start = sol.list_start;
	ListNode* top = start;
	for(int i=0; i<5; i++) {
		top = top->next;
	}
	
	ListNode* prev = top;
	auto p = sol.reverse(top->next, 4);
	prev->next = p.first;
	
	cout << endl; sol.traverse(start);
	
	return 0;
}