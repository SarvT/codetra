class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int lg=INT_MAX, mx=INT_MAX;
        for(auto it:nums){
            if(it<=lg) lg=it;
            else if(it<=mx) mx=it;
            else return true;
        }
        return false;
    }
};
