class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int x = nums[0], cnt = 0, xCnt = 0, n = nums.size();
        for (auto& num : nums) {
            if (num == x) cnt++;
            else cnt--;
            if (cnt == 0) {
                x = num;
                cnt = 1;
            }
        }

        for (auto& num : nums) {
            if (num == x) xCnt
++;
        }

        cnt = 0;
        for (int index = 0; index < n; index++) {
            if (nums[index] == x) cnt++;
            int remainingCount = xCnt
 - cnt;
            if (cnt * 2 > index + 1 && remainingCount * 2 > n - index - 1) return index;
        }
        return -1;
    }
};
