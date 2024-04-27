class Solution {
public:
    unordered_map<char, vector<int>> index;
    int findRotateSteps(string ring, string key) {
        int m = key.size(), n = ring.size();
        vector<vector<int>> memo(m+1, vector<int>(n+1,0));
        for(int i=0; i<ring.size(); i++) index[ring[i]].push_back(i);

        for(int i=m-1; i>=0; i--) {
            for(int j=n-1; j>=0; j--) {

                char currChar = key[i];
                int ans = INT_MAX;
                for(int ind: index[currChar]) {
                    int lftRotateStep = abs(ind-j), rgtRotate = n-lftRotateStep;
                    ans = min(ans, min(lftRotateStep, rgtRotate)+ memo[i+1][ind]);
                }
                memo[i][j] = 1+ans;
            }
        }
        return memo[0][0];
    }
};
