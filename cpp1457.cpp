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
int cnt(TreeNode* root,int bit){
        if(!root) return 0;
        if(!root->left&&!root->right) return __builtin_popcount(bit^(1<<root->val))<=1;
        return cnt(root->left,bit^(1<<root->val))+cnt(root->right,bit^(1<<root->val));
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        return cnt(root,0);
    }
};
