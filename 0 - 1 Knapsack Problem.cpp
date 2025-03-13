//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(int i, int w, vector<int>&v, vector<int>&wt, 
    vector<vector<int>>&dp){
        if(i<0) return 0;
        if(dp[i][w]!=-1) return dp[i][w];
        int ntake=solve(i-1, w, v, wt, dp);
        int take=-1e9;
        if(wt[i]<=w) take=v[i]+solve(i-1, w-wt[i], v, wt, dp);
        return dp[i][w]=max(take, ntake);
    }
    
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n=wt.size();
        vector<vector<int>>dp(n, vector<int>(W+1, -1));
        return solve(n-1, W, val, wt, dp);
    }
};


//{ Driver Code Starts.

int main() {
    // Taking total test cases
    int testCases;
    cin >> testCases;
    cin.ignore();
    while (testCases--) {
        // Reading number of items and capacity
        int numberOfItems, capacity;
        vector<int> weights, values;
        string input;
        int number;

        // Read capacity and number of items
        getline(cin, input);
        stringstream ss(input);
        ss >> capacity;      // The first number is the capacity
        ss >> numberOfItems; // The second number is the number of items

        // Read values
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            values.push_back(number);
        }

        // Read weights
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            weights.push_back(number);
        }

        Solution solution;
        cout << solution.knapsack(capacity, values, weights) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
