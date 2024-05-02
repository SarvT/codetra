class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<int>());
        for(int i=0;i<nums.size();i++){
        for(int j=i+1;j<nums.size();j++)if(nums[i]+nums[j]==0)return nums[i];
       }
       return -1;
    }
};
