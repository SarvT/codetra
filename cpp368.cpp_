class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1);
        int ans = 1;
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) if(nums[i] % nums[j] == 0) dp[i] = max(dp[i], 1 + dp[j]);
            ans = max(ans, dp[i]);
        }
        int it = -1;
        for(int i = 0; i < n; i++) {
            if(dp[i] == ans) {
                it = i;
                break;
            }
        }
        vector<int> res;
        int num = it;
        res.push_back(nums[it]);
        int sol = ans;
        for(int i = it - 1; i >= 0; i--) {
            if(dp[i] == sol - 1 && nums[num] % nums[i] == 0) {
                res.push_back(nums[i]);
                sol--;
                num = i;
            }
        }
        return res;
    }
};
