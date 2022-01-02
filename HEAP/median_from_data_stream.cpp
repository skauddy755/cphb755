#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
#define log1(a) for(auto x:a)cout << x <<" ";cout <<endl;
#define log2(a,r,c) for(int i=0;i<r;i++){for(int j=0;j<c;j++)cout<<a[i][j]<<" ";cout << endl;}

using namespace std;
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};

class Solution {
	
	private:
	public:
	
	priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
    
    
    void addNum(int num) {
        
        /*  Condition:
            (countLeft - countRight) <= 1
        */
        
        if(!right.empty() && (num > right.top())) right.push(num);
        else left.push(num);
        
        int countLeft = left.size();
        int countRight = right.size();
        
        int diff = countLeft - countRight;
        if(diff == -1) {
            int x = right.top(); right.pop();
            left.push(x);
        }
        else if(diff == 2) {
            int x = left.top(); left.pop();
            right.push(x);
        }
    }
    
    double findMedian() {
        int countLeft = left.size();
        int countRight = right.size();
        
        int diff = countLeft - countRight;
        
        double median = (diff == 0)
            ? ((1.0 * (left.top() + right.top())) / 2)
            : left.top();
        return median;
    }
	
};

int main()
{
	// taking inputs:
	// --------------
	vector<string> cmd = {"MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"};
	vector<array<int,1>> arg = {{}, {1}, {2}, {}, {3}, {}};
	
	
	// Calling the working function:
	// -----------------------------
	Solution sol;
	int n = cmd.size();
	
	for(int i=0; i<n; i++) {
		if(cmd[i] == "findMedian") {
			cout << sol.findMedian() << " ";
		}
		else if(cmd[i] == "addNum"){
			sol.addNum(arg[i][0]);
			cout << "null ";
		}
		else {
			cout << "null ";
		}
	}
	
	return 0;
}