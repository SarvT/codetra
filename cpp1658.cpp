class Solution {
public:
    int rec(vector<int>& nums, int x){
        long long f = 0, s = 0, sum = 0, ans = INT_MIN, n = nums.size();
        while(s<n){
            sum+=nums[s];
            if(sum == x) ans = max(ans, s-f+1);
            else if(sum>x){
                while(sum>x) sum -= nums[f++];
                if(sum == x) ans = max(ans, s-f+1);
            }
            s++;
        }
        return ans;
    }
    int minOperations(vector<int>& nums, int x) {
        long long sol=0, n = nums.size();

        for(auto x: nums) sol+= x;
        int t = sol-x;

        if(t<0) return -1;
        if(t==0) return n;
        int w = rec(nums, t);
        if(w == INT_MIN) return -1;
        return (n-w);
    }
};
