// Leet
// Not worked
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        for (int i = 1; i < n; i++) {
            if(nums[i] || nums[i-1] >= n) return 1;
            else if (nums[i] + nums[i-1] >= n) return 2;
            // maxi = max(maxi, i + nums[i]);
        }
        return 0;
    }
};

// worked
class Solution
{
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jumps = 0, currEnd = 0, currFarthest = 0;
        
        for(int i = 0; i < n - 1; i++) {

            currFarthest = max(currFarthest, i + nums[i]);
            
            if(i == currEnd) {
                jumps++;
                currEnd = currFarthest;
            }
        } 
        
        return jumps;
    }
};
