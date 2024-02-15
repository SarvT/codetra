class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
    long long sum = 0;
    vector<long long> presum;
    sort(nums.begin(), nums.end());
    for(auto n: nums) { presum.push_back(sum); sum += n; }
    for(int i = nums.size()-1; i >= 2; --i){
        if(nums[i] < presum[i]) return ( presum[i] + (long long)nums[i] );
    }
    return -1;
    }
};
