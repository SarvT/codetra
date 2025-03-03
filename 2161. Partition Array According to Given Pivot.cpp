class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans(nums.size());
        int smalls = 0;
        int largers = nums.size() - 1;
        for (int i = 0, j = nums.size() - 1; i < nums.size(); i++, j--) {
            if (nums[i] < pivot) {
                ans[smalls] = nums[i];
                smalls++;
            }
            if (nums[j] > pivot) {
                ans[largers] = nums[j];
                largers--;
            }
        }
        while (smalls <= largers) {
            ans[smalls] = pivot;
            smalls++;
        }
        return ans;
    }
};
