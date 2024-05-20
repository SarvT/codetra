class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int size = nums.size();
        int totalXor = 0;
        for(int indxMask = 0; indxMask < (1<<size); indxMask++){
            int currSubXor = 0;
            for(int indx = 0; indx < size; indx++){
               if(((1 << indx) & indxMask) != 0){
                  currSubXor = (currSubXor ^ nums[indx]);
               }
            }
            totalXor += currSubXor;
        }
        return totalXor;
    }
};
