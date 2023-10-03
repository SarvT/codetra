// worked
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int cnt=0;
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                if(nums[i]==nums[j] && i<j) cnt++;
            }
        }
        return cnt;
    }
};

// optimal

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> counts;
        int ans = 0;
        
        for (int num: nums) {
            ans += counts[num];
            counts[num]++;
        }
        
        return ans;
    }
};
