/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
int solve(TreeNode* root, int& moves) {
        if (root == NULL)return 0;
        int lft = solve(root->left, moves);
        int rgt = solve(root->right, moves);
        int extra = (lft + rgt + root->val) - 1;
        moves += abs(lft) + abs(rgt);
        return extra;
    }
    int distributeCoins(TreeNode* root) {
        int moves = 0;
        if (!root->left && !root->right)return 0;
        solve(root, moves);
        return moves;
    }
};
