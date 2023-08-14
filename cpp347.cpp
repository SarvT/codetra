// not worked --> took the decription wrong
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int i:nums) mp[i]++;
        vector<int> v;
        
        for(int i=0; i<nums.size(); i++){
            if(mp[nums[i]]>=k && (find(v.begin(), v.end(), nums[i]) == v.end())) v.emplace_back(nums[i]); 
        }
        return v;
    }
};

// worked
class Solution {
public:
static bool cmp(pair<int, int>& a, pair<int, int>& b) { //This comparator is so important otherwise it will only partially
        return a.second > b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int i:nums) mp[i]++;
        vector<pair<int, int>> pi;
        for(auto a: mp){
            pi.emplace_back(a);
        }
        sort(pi.begin(), pi.end(), cmp);
        vector<int> v;
        for(auto a:pi){
            v.emplace_back(a.first);
            if(v.size()==k) break;

        }
        return v;
    }
};
