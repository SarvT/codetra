// worked mannnnnnn...
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        sort(nums.begin(), nums.end());
        unordered_map<int, int> mp;
        for(int i:nums) mp[i]++;
        vector<int> v;
        for(int i=0; i<nums.size(); i++){
            if(mp[nums[i]]==1) v.emplace_back(nums[i]);
        }
        return v;
    }
};
