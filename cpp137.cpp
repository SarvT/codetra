// Leet
// Not worked
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i=1; i<nums.size()-1; i++){
            if(nums[i] != nums[i-1] && nums[i] != nums[i+1]) return nums[i];
            else if(i+1>=nums.size() && nums[i] != nums[i-1]) return nums[i];
        }
        return -1;
    }
};

// worked
class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    int ones = 0;
    int twos = 0;

    for (const int num : nums) {
      ones ^= (num & ~twos);
      twos ^= (num & ~ones);
    }

    return ones;
  }
};
