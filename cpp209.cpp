// Leet
// Not worked
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size()-1, i=n, l=n-2;
        int cnt=0, sum=0;
        sort(nums.begin(), nums.end());
        if(nums[n]==target) return 1;
        while(l>=0){
            if(sum > target){
                
            }
        }
        return cnt;
    }
};

// worked
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, right = 0, sumOfCurrentWindow = 0;
        int res = INT_MAX;

        for(right = 0; right < nums.size(); right++) {
            sumOfCurrentWindow += nums[right];

            while (sumOfCurrentWindow >= target) {
                res = min(res, right - left + 1);
                sumOfCurrentWindow -= nums[left];
                left++;
            }
        }

        return res == INT_MAX ? 0 : res;
    }
};
