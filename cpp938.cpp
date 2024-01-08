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
bool traverse(int x, int low, int high){
        return x >= low && x <= high;
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        return (traverse(root->val, low, high) ? root->val : 0)+(root->left != nullptr ? rangeSumBST(root->left, low, high) : 0)+(root->right != nullptr ? rangeSumBST(root->right, low, high) : 0);
    }
};
