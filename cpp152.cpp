Leet
Not worked
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int l=0, h=nums.size()-1;
        if(h==0) return nums[0];
        int maxi=0;
        while(l+1<=h){
            maxi=max(maxi, nums[l]*nums[l+1]);
            l++;
        }
        return maxi;
    }
};

Worked
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = nums[0];
        int mini = nums[0];
        int ans = nums[0];
        for(int i=1; i<nums.size(); i++){
            if(nums[i]<0){
                swap(maxi,mini);
            }
            maxi = max(nums[i],maxi*nums[i]);
            mini = min(nums[i],mini*nums[i]);
            ans = max(ans,maxi);
        }
        return ans;
    }
};
