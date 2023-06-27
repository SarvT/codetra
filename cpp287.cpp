// Leet
// Worked
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int sol;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size();j++){
                if(nums[i] == nums[j] && i!=j){
                    sol = nums[j];
                    break;
            }
            }
        }
        return sol;
    }
};


// Worked
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int t = nums[0], h=t;
        do{
            t = nums[t];
            h = nums[nums[h]];
        } while(t != h);

        t=nums[0];
        while(t != h){
            t = nums[t];
            h = nums[h];
        }
      return h;
    }
};
