// Leet
// Worked
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i=0, j=0, k=0;
        for(int num:nums){
            if(num == 0) i++;
            if(num == 1) j++;
            if(num == 2) k++;
        }
        for(int a=0; a<nums.size(); a++){
            if(i>0){
                i--;
                nums[a] = 0;
            }
            else if(j>0){
                j--;
                nums[a] = 1;
            } 
            else{
                k--;
                nums[a] = 2;
            }
        }
    }
};
