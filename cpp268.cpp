//worked
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int k = nums[0];
        if(nums[0]!=0)return 0;
        for(int i=0; i<nums.size();i++){
            if(nums[i]!=k) return k;
            k++;
        }
        return k;
    }
};


// optimal
        int n = nums.size(), sum = n * (n + 1) / 2;
        for (int val : nums) sum -= val;
        return sum;
