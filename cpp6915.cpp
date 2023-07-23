// leet
// not worked
class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        int n=nums.size()-1;
        vector<int>vis(n, 0);
        int maxi = 0, sum = nums[0];
        for(int i=0; i<n-1; i++){
            
            if(nums[i]<=nums[i+1]){
                
                sum+=nums[i+1]+nums[i];
                nums[i]=0;
                vis[i]=1;
            } else if(i>0 && nums[i-1]<nums[i+1] && vis[i-1]==0){
                sum+=nums[i-1]+nums[i+1];
                nums[i-1]=0;
            }
            maxi=max(maxi, sum);
        }
        return maxi;
    }
};

// worked
