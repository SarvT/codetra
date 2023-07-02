// Leet
// Worked
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n=nums.size()-1;
        while(k>-1){
            if(k==0) return nums[n+1];
            k--;
            n--;
        }
        return nums[0];
    }
};
