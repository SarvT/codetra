// Leet
// Not worked
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int sum, cnt=0;
        int n = nums.size();
        for(int i=0; i<n-2; i++){
            if(nums[i]+nums[i+1]== k){
                cnt++;
                i+=2;
            }
        }
        return cnt;
    }
};

// Worked
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int sum, cnt=0;
        int i=0, n = nums.size()-1;
        while(i<n){
            if(nums[i]+nums[n]==k){
                i++;
                n--;
                cnt++;
                continue;
            }
            if(nums[i]+nums[n]>k) n--;
            else i++;
        }
        return cnt;
    }
};
