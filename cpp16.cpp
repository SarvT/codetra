// Leet
// Not worked
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int i=0, sum, n=nums.size()-1;
        while(i<=n){
            sum+=nums[i]
        }
    }
};


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        long long ans=INT_MAX;
        int s=0, n=nums.size()-1, e=n;
        for(int i=0; i<n+1; i++){
            s=i+1;
            e=n;
            while(s<e){
                long long curr=nums[s]+nums[e]+nums[i];
                if(abs(curr-target) <= abs(ans-target)) ans = curr;
                if(curr>target) e--;
                else s++;
                while(s<n && nums[s] == nums[s+1]) s++;
            }
        }
        return ans;
    }
};

// Worked
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size() < 3) return 0;
        int closest = nums[0]+nums[1]+nums[2];
        sort(nums.begin(), nums.end());
        for(int l = 0 ; l < nums.size()-2 ; ++l) {
            if(l > 0 && nums[l] == nums[l-1]) continue;
            int m = l+1;
            int r = nums.size()-1;            
            while(m < r) {
                int curSum = nums[l]+nums[m]+nums[r];
                if(curSum == target) return curSum;
                if(abs(target-curSum)<abs(target-closest)) {
                    closest = curSum;
                }
                if(curSum > target) {
                    --r;
                } else {
                    ++m;
                }
            }
        }
        return closest;
    }
};
