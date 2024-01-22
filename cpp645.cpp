// didn't worked
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size(), order=1, j=0, cause1=1, cause2=1;
        if(nums[0]>nums[n-1]) order=0;
        if(order){
            for(int i=nums[0]; i<=n; i++){
                if(nums[j]!=i) {
                    cause1=nums[j];
                    cause2=i;
                }
                j++;
            }
        } else {
            for(int i=nums[0]; i>=nums[n-1]; i--){
                if(nums[j]!=i) {
                    cause1=nums[j];
                    cause2=i;
                    break;
                }
                j++;
            }
        }
        return {cause1, cause2};

    }
};



// worked
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int cause1 = -1, cause2 = -1, n = nums.size();
        vector<int> vec(n+1,0);

        for(int num : nums)vec[num]++;
        for(int index=1; index<n+1; index++)
            if(vec[index] == 0) cause2 = index; 
            else if(vec[index]>1) cause1 = index;

        return {cause1,cause2};
    }
};
