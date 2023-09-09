not worked
class Solution {
private:
    void rec(vector<int>& nums, int target, pair<int, int> pa, int l){
        if(pa.first == target){
            pa.second+=1;
            return;
        }
        if(pa.first > target) return;
        for(int i=l; i<nums.size(); i++){
            pa.first+=nums[i];
            rec(nums, target, pa, i);
            pa.first-=nums[i];
            // rec(nums, target, pa, i);
        }
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        pair<int, int> pa;
        pa.first = 0;
        pa.second = 0;
        rec(nums, target, pa, 0);
        return pa.second;

    }
};


worked
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> memo;

        return helper(target, nums, memo);
    }

private:
    int helper(int n, vector<int>& nums, unordered_map<int, int>& memo) {
        if (memo.find(n) != memo.end()) return memo[n];
        if (n == 0) return 1;
        if (n < nums[0])return 0;

        int count = 0;
        for (int num : nums) {
            if (n - num < 0) break;
            count += helper(n - num, nums, memo);
        }

        memo[n] = count;
        return count;
    }
};




class Solution {
public:
    int combinationSum4(std::vector<int>& nums, int target) {
        std::vector<unsigned int> dp(target + 1, 0);
        dp[0] = 1;
        
        for (int i = 1; i <= target; ++i) {
            for (int num : nums) {
                if (i - num >= 0) {
                    dp[i] += dp[i - num];
                }
            }
        }
        
        return dp[target];
    }
};
