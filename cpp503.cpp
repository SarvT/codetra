class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res(nums.size());
        stack<int> s;
        for(int i=2*nums.size()-1; i>=0; i--){
            while(!s.empty() && nums[s.top()] <= nums[i%nums.size()]) s.pop();
            res[i%nums.size()] = s.empty()? -1: nums[s.top()];
            s.push(i%nums.size());
        }
        return res;
    }
};
