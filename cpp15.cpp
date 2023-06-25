Leet
Not Worked
class Solution {
public:
    void sum(vector<int>& nums, vector<vector<int>>& sol, vector<int>& v1, int sum, int ind){
        if(sum == 0){
            sol.emplace_back(v1);
            return;
        }
        for(int i=ind; i<nums.size(); i++){
            // if(i != i-1 && nums[i] != nums[i+1])
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        int sum;
        vector<vector<int>> sol;
        vector<int> v1;
        sum(nums, sol, v1, sum);
        return sol;
        // for(int i=0; i<nums.size(); i++){

        // }
    }
};

Worked
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++)
        {
            if(i>0&&nums[i]==nums[i-1])continue;
            int s=i+1;
            int e=nums.size()-1;

            while(s<e)
            {
                int sum=nums[i]+nums[s]+nums[e];
                if(sum<0)
                {
                    s++;
                }
                else if(sum>0)
                {
                    e--;

                }
                else
                {
                    vector<int>temp={nums[i],nums[s],nums[e]};
                    ans.push_back(temp);
                    s++;
                    e--;
                     while(s < e and (nums[s-1] == nums[s])) s++;
                        while(s < e and (nums[e+1] == nums[e])) e--;
                }
            }
        }
        return ans;
        
    }
};
