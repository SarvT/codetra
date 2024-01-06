class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size(); 
        vector<pair<int, int>> vec(n);
        for(int i = 0; i < n; i++) vec[i] = {startTime[i], i};
        sort(vec.begin(), vec.end());
        vector<int> dp(n+1, 0); 
        for(int i = n-1; i > -1; i--)
            dp[i] += max(dp[i+1], profit[vec[i].second] + dp[lower_bound(vec.begin() + i, vec.end(), make_pair(endTime[vec[i].second], 0)) - vec.begin()]);
        return dp[0];
    }
};
