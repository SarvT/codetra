// partial
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxiInc = 0, maxiDec = 0, cnt = 1, n=nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1])
                cnt++;
            else if (nums[i] < nums[i - 1]) {
                maxiInc = max(maxiInc, cnt);
                cnt = 0;
            }
        }
        maxiInc = max(maxiInc, cnt);
        cnt=1;
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i - 1])
                cnt++;
            else if (nums[i] > nums[i - 1]) {
                maxiDec = max(maxiDec, cnt);
                cnt = 0;
            }
        }
        maxiDec = max(maxiDec, cnt);
        return max(maxiInc, maxiDec);

    }
};



// worked
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int incLength = 1, decLength = 1;
        int maxLength = 1;

        for (int pos = 0; pos < nums.size() - 1; pos++) {
            if (nums[pos + 1] > nums[pos]) {
                incLength++;
                decLength = 1;
            } else if (nums[pos + 1] < nums[pos]) {
                decLength++;
                incLength = 1;
            } else {
                incLength = 1;
                decLength = 1;
            }
            maxLength = max(maxLength, max(incLength, decLength));
        }
        return maxLength;
    }
};
