class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int mx = 0, sB = 0, mn = INT_MAX, sM = INT_MAX;
        
        for (int num : nums) {
            if (num > mx) {
                sB = mx;
                mx = num;
            } else sB = max(sB, num);
            
            if (num < mn) {
                sM = mn;
                mn = num;
            } else sM = min(sM, num);
        }
        
        return mx * sB - mn * sM;
    }
};
