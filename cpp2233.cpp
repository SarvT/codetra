class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> queue(nums.begin(), nums.end());
        int mod=1000000007;
        while(k--){
            int t=queue.top();
            t = t+1;
            queue.pop();
            queue.push(t);
        }
        long long int ans=1;
        while(!queue.empty()) {
            int t=queue.top();
            queue.pop();
            ans = (ans*t)%mod;
        }
        return ans;
    }
};
