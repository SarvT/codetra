// giving TLE but working partially
class Solution {
public:
    int greaterCount(vector<int> arr, int i){
        int cnt=0;
        for(auto it: arr) if(it>i)cnt++;
        return cnt;
    }
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1, arr2;
        arr1.emplace_back(nums[0]);
        arr2.emplace_back(nums[1]);
        // cout << arr1[0] << arr2[0];
        for(int i=2; i<nums.size(); i++){
            if(greaterCount(arr1, nums[i]) > greaterCount(arr2, nums[i])){
                arr1.emplace_back(nums[i]);
            }else if(greaterCount(arr1, nums[i]) < greaterCount(arr2, nums[i])){
                arr2.emplace_back(nums[i]);
            } else if(greaterCount(arr1, nums[i]) == greaterCount(arr2, nums[i])){
                // if(arr1.size()==arr2.size()) arr1.emplace_back(nums[i]);
                if(arr1.size()>arr2.size()) arr2.emplace_back(nums[i]);
                else arr1.emplace_back(nums[i]);
            }else arr1.emplace_back(nums[i]);
        }
        for(int i=0; i<arr2.size(); i++) arr1.emplace_back(arr2[i]);                                                        
        return arr1;
    }
};
