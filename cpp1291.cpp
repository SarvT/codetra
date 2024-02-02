class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        int l = floor(log10(low) + 1);
        int h = floor(log10(high) + 1);
        string superset = "123456789";
        for(int i = l; i <= h; i++) {
            for(int j = 0; j <= 9 - i; j++) {
                int num = stoi(superset.substr(j, i));
                if(num >= low && num <= high)ans.push_back(num);
            }
        }
        return ans;
    }
};
