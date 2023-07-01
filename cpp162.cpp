// Leet
// Worked
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int i=0, j=nums.size()-1;
        pair<int, int>maxi;
        maxi.first=i;
        maxi.second=nums[i];
        if(nums[i]<nums[j]){
            maxi.first=j;
            maxi.second=nums[j];
        }
        i++;
        j--;
        // maxi.second=INT_MIN;
        while(i<=j){
            if(nums[i]>maxi.second){
                maxi.first=i;
                maxi.second=nums[i];
                i++;
            }
            else if(nums[j]>maxi.second){
                maxi.first=j;
                maxi.second=nums[j];
                j--;
            } else{
                i++;
                j--;
            }
        }
        return maxi.first;
    }
};
