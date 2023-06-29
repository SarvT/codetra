Leet
Not working
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long val1, val2=0;
        int l=0, h=nums.size()-1;
        // if()
        while(l<=h){
            val1^=nums[l++];
            // val2^=nums[h--];

        }
        vector<int> ans;
        ans.emplace_back(val1);
        ans.emplace_back(val2);
        return ans;
    }
};

Worked
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int val=1, val2=0;
        int l=0, h=nums.size()-1;
        for(int i:nums) val2^= i;
        while(true){
            if(val2 & val) break;
            val<<=1;
        }
        int solOne=0;
        for(int i:nums){
            if(i&val) solOne^=i;
        }
        int solTwo = solOne^val2;
        vector<int> ans;
        ans.emplace_back(solOne);
        ans.emplace_back(solTwo);
        return ans;
    }
};
