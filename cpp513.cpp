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
    void solve(TreeNode* root, int level, int &height, int& ans){
        if(!root)return;
        if(level > height){
            height= level;
            ans = root->val;
        }
        solve(root->left, level+1, height, ans);
        solve(root->right, level+1, height, ans);
    }
    int findBottomLeftValue(TreeNode* root) {
        int level=0, height =-1, ans =0;
        solve(root,  level, height, ans);
        return ans;
    }
};
