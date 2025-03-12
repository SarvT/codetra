//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//Back-end complete function Template for C++

class Solution {
  public:
    int rec(vector<int>& cost, int st, int en, vector<int>& dp){
        if(st==en-1)return cost[en-1];
        if(st==en-2)return cost[en-2];
        if(dp[st] != -1)return dp[st];
        dp[st]= cost[st]+min(rec(cost, st+1, en, dp), rec(cost, st+2, en, dp));
        return dp[st];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        // Write your code here
        int n= cost.size(), i=0;
        vector<int> dp(n+1, -1);
        int mini = min(rec(cost, i, n, dp), rec(cost, i+1, n, dp));
        return mini;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t-- > 0) {
        string str;
        getline(cin, str);

        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution sln;
        int res = sln.minCostClimbingStairs(arr);
        cout << res << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends
