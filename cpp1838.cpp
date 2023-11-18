class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int length = nums.size();

        vector<long> differences(length);
        for (int i = 1; i < length; i++)
            differences[i] = static_cast<long>(nums[i]) - static_cast<long>(nums[i - 1]);

        vector<long> prefixSums(length);
        for (int i = 1; i < length; i++)
            prefixSums[i] = prefixSums[i - 1] + differences[i];

        int low = 1, high = length;

        while (low < high) {
            int mid = (high - low + 1) / 2 + low;

            if (isPossible(nums, differences, prefixSums, mid, k))
                low = mid;
            else
                high = mid - 1;
        }

        return low;
    }

private:
    bool isPossible(const vector<int>& nums, const vector<long>& differences, const vector<long>& prefixSums, int freq, int k) {
        int length = differences.size();

        long times = 0;

        for (int i = freq - 2; i >= 0; i--)
            times += static_cast<long>(nums[freq - 1]) - static_cast<long>(nums[i]);

        long minTimes = times;

        for (int i = freq; i < length; i++) {
            times = times - (prefixSums[i - 1] - prefixSums[i - freq]) + differences[i] * (freq - 1);
            minTimes = min(minTimes, times);
        }

        return minTimes <= static_cast<long>(k);
    }
};
