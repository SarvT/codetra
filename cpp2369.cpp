class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n=nums.size();
        vector<bool> dp;
        dp.emplace_back(true);

        for(int i=0; i<n; i++){
            int dpIdx = i+1;
            bool ans=false;

            if (i > 0 && nums[i] == nums[i - 1]) ans |= dp[(dpIdx - 2) % 3];
            if (i > 1 && nums[i] == nums[i - 1] && nums[i] == nums[i - 2]) ans |= dp[(dpIdx - 3) % 3];
            if (i > 1 && nums[i] == nums[i - 1] + 1 && nums[i] == nums[i - 2] + 2) ans |= dp[(dpIdx - 3) % 3];

            dp[dpIdx % 3] = ans;
        }
        return dp[n % 3];
    }
};
