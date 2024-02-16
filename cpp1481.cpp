class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> freqMap;
        for (int num : arr) freqMap[num]++;

        vector<pair<int, int>> freqVec(freqMap.begin(), freqMap.end());
        sort(freqVec.begin(), freqVec.end(), [](const auto& a, const auto& b) {
            return a.second < b.second;
        });

        int uniqueCount = freqVec.size();
        for (const auto& entry : freqVec) {
            if (k >= entry.second) {
                k -= entry.second;
                uniqueCount--;
            } else break;
        }

        return uniqueCount;
    }
};
