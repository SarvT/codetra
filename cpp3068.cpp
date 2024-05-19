class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long total = accumulate(nums.begin(), nums.end(), 0ll), totalDiff = 0, diff, minDiff = numeric_limits<int>::max();
        int positiveCount = 0;
        for(auto p : nums){
            diff = (p^k) - p;
            
            if(diff > 0){
                totalDiff += diff;
                positiveCount++;
            }
            minDiff = min(minDiff, abs(diff));
        }
        if(positiveCount % 2 == 1)totalDiff = totalDiff - minDiff;
        return total + totalDiff;
    }
};
