class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> freq(101, 0);
        for (int i:nums)freq[i]++;
        
        int ans = 0, temp = 0;    
        
        for (int i = 1; i < 101; i++){
            if (freq[i] == temp) ans += freq[i];
            else if (freq[i] > temp) {
                ans = freq[i];
                temp = freq[i];
            }
        }
        
        return ans;
    }
};
