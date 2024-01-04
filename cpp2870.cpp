// Halfway approach
class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int>mp;
        int cnt=0;
        for(auto it:nums) mp[it]++:
        for(int it=0; it<nums.size(); it++){
            if(mp[nums[it]]==0) continue;
            else if(mp[nums[it]]) return -1;
            else{
                if(mp[nums[it]]&1){
                    
                }
            }
        }
    }
};



// worked
class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto a: nums)mp[a]++;

        int count=0;
        for(auto a: mp){
            int t = a.second;
            if(t==1)return -1;
            count += t/3;
            if(t%3)count++;
        }
        return count;
    }
};
