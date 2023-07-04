// Leet
// Not worked
class Solution {
public:
    long long countQuadruplets(vector<int>& nums) {
        int n=nums.size();
        for(int i=0; i<n; i++){
            int j=i+1;
            int k=i+2;
            int l=i+3;
            
        }
    }
};

// worked
class Solution {
public:
    long long countQuadruplets(vector<int>& a) {
        long long res = 0;
        int n = a.size();
        vector<vector<int>> left(n, vector<int>(n+1, 0));
        vector<vector<int>> right(n, vector<int>(n+1, 0));
        for (int i = 1; i < n; ++i) {
            left[i] = left[i-1];
            for (int j = a[i-1] + 1; j <= n; ++j) left[i][j]++;
        }
        for (int i = n-2; i >= 0; --i) {
            right[i] = right[i+1];
            for (int j = 0; j < a[i+1]; ++j) right[i][j]++;
        }
        for (int j = 0; j < n; ++j) {
            for (int k = j+1; k < n; ++k) {
                if (a[j] <= a[k]) continue;
                res += left[j][a[k]] * right[k][a[j]];
            }
        }
        return res;
    }
};
