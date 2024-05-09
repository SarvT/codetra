class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(), greater<int>());
        long long result = 0;
        int decrement = 0;
        while (k > 0 && happiness[decrement] - decrement > 0) {
            result += happiness[decrement] - decrement;
            k--;
            decrement++;
        }
        return result;
    }
};
