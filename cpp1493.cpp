class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int xeroes=0, maxi=0, i=0;
        for(int j=0; j<nums.size(); j++){
            xeroes+=(nums[j]==0);
            while(xeroes>1){
                xeroes-=(nums[i]==0);
                i++;
            }
            maxi = max(maxi, j-i);
        }
        return maxi;
    }
};
