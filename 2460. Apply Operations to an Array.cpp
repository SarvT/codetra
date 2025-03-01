class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        int idx = 0;

        for (int index = 0; index < n; index++) {
            if (index < n - 1 && nums[index] == nums[index + 1] &&
                nums[index] != 0) {
                nums[index] *= 2;
                nums[index + 1] = 0;
            }

            if (nums[index] != 0) {
                if (index != idx) swap(nums[index], nums[idx]);
                idx++;
            }
        }

        return nums;
    }
};
