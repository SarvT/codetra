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

// low performed
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
      vector<int> res(2, -1);
      for(int i=0; i<nums.size(); i++){
          if(nums[i] == target){
              if(res[0] == -1) res[0] = i;
              else res[1] = i;
          }
      }
      if(res[0] != -1 && res[1] == -1) res[1]=res[0];
      return res;
    } 
};
