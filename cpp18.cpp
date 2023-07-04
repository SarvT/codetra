// Leet
// Not worked
class Solution {
public:

    void rec(vector<int>& nums, vector<int>& v1, vector<vector<int>>& sol, int target, int l, int sum){
        if(l == nums.size()) return;
        if(sum == target && v1.size() == 4){
            sol.emplace_back(v1);
            return;
        }
        if(v1.size() == 4 && sum == target) return;
            // accumulate(v1.begin(), v1.end(), 0)
        for(int i=l; i<nums.size()-1; i++){
            v1.emplace_back(nums[i]);
            sum += nums[i];
            rec(nums, v1, sol, target, i, sum);
            v1.pop_back();
            sum -= nums[i];

        }
        // rec(nums, v1, sol, target, l+1, sum);
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> sol;
        vector<int> v1;
        rec(nums, v1, sol, target, 0, 0);
        return sol;
    }
};


// Worked
class Solution {
public:

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> output;
        for(int i=0; i<n-3; i++){
            for(int j=i+1; j<n-2; j++){
                long long newTarget = (long long)target - (long long)nums[i] - (long long)nums[j];
                int low = j+1, high = n-1;
                while(low < high){
                    if(nums[low] + nums[high] < newTarget){
                        low++;
                    }
                    else if(nums[low] + nums[high] > newTarget){
                        high--;
                    }
                    else{
                        output.push_back({nums[i], nums[j], nums[low], nums[high]});
                        int tempIndex1 = low, tempIndex2 = high;
                        while(low < high && nums[low] == nums[tempIndex1]) low++;
                        while(low < high && nums[high] == nums[tempIndex2]) high--;
                    }
                }
                while(j+1 < n && nums[j] == nums[j+1]) j++;
            }
            while(i+1 < n && nums[i] == nums[i+1]) i++;
        }
        return output;
    }
};
