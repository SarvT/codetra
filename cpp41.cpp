// Leet
// Not working

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int j=1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] > j && nums[i] <= 0) return j;
            j++;
        }
        for(int i=0; i<nums.size(); i++){
            if(m[i]==0) return i
        }
        return j;
    }
};

// Working
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int, int> m;
        for(auto i:nums) m[i]++;
        for(int i=1; i<=nums.size()+1; i++){
            if(m[i]==0) return i;
        }
        return -1;
    }
};
