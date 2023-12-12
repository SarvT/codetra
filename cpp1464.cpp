// worked
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        return ((nums[n-1]-1)*(nums[n-2]-1));
    }
};

// optimized
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max1 = INT_MIN, max2 = INT_MIN;
        for(int num:nums){
            if(num>=max1){
                max2 = max1;
                max1 = num;
            }
            else if(num>max1) max1=num;
        }
        return ((max1-1)*(max2-1));
    }
};
