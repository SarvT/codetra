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
    int dtr = 0;
    int gnd(TreeNode* curr, int& dtr) {
        if (curr == NULL)return 0;

        int lth = gnd(curr->left, dtr);
        int rth = gnd(curr->right, dtr);

        dtr = max(dtr, lth + rth);

        return 1 + max(lth, rth);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        gnd(root, dtr);
        return dtr;
    }
};
