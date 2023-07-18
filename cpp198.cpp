Leet
not worked
class Solution {
public:
    int rob(vector<int>& nums) {
        int sum1 = 0, sum2= 0, l=0;
        for(int n:nums){
            if(!l) {
                sum1+=n;
                l=1;
            }
            else if(l){

                sum2+=n;
                l=0;
            } 
        }
        return max(sum1, sum2);
    }
};


worked
class Solution {
public:
    int rob(vector<int>& nums) {
        int prev = nums[0], prev2= 0, n=nums.size();
        for(int i=1;i<n;i++){
            int take = nums[i];
            if(i>1) take+=prev2;
            int notTake = 0+prev;
            int curi = max(take, notTake);
            prev2=prev;
            prev=curi;
        }
        return prev;
    }
};
