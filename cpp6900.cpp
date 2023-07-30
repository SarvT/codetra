class Solution {
public:
    void subArr(vector<int>& nums, vector<int>& v1, vector<vector<int>>& v, int l, int n){
        if(l >= n) return;
        v.emplace_back(v1);
        for(int i=l; i<n; i++){
            subArr(nums, v1, v, i, n);
            v1.emplace_back(nums[i])
        }
    }
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> st;
        vector<vector<int>> v;
        int n = nums.size();
        for(int num:nums) st.insert(num);
        int setN = st.size();
        
        
        return 0;
    }
};
