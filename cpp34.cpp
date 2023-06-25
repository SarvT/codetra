// Leet
// Worked
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
      int first = -1, last = -1;
      for(int i=0; i<nums.size(); i++){
          if(nums[i] == target){
              if(first == -1) first = i;
              else last = i;
          }
      }
      if(first != -1 && last == -1) last=first;
      vector<int> res;
      res.emplace_back(first);
      res.emplace_back(last);
      return res;
    } 
};
