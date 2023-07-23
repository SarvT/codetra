// leet
class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        if (!(n & 1)) return {};

        vector<vector<TreeNode*>> dp(n + 1);

        dp[1].push_back(new TreeNode(0));
        for (int count = 3; count <= n; count += 2) {
            for (int i = 1; i < count - 1; i += 2) {
                int j = count - 1 - i;
                for (auto left : dp[i]) {
                    for (auto right : dp[j]) {
                        TreeNode* root = new TreeNode(0, left, right);
                        dp[count].push_back(root);
                    }
                }
            }
        }
        
        return dp[n];
    }
};
