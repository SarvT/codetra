class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long>dp(n);

        for(int i = n-1 ;i >= 0 ;i--){
            int nxt = questions[i][1]+i+1;
            dp[i] = max(questions[i][0]+(nxt<n?dp[nxt]:0),(i+1<n?dp[i+1]:0));
        }
        return dp[0];
    }
};
