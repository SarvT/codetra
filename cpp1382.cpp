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
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> arr;
        toArr(root, arr);
        int n = arr.size();
        int l = 0;
        int r = n - 1;

        return create(l, r, arr);
    }

    void toArr(TreeNode * root, vector<int> & arr) {
        if (!root) return;
        toArr(root->left, arr);
        arr.push_back(root->val);
        toArr(root->right, arr);
    }

    TreeNode * create(int l, int r, vector<int> & arr) {
        if (l > r) return NULL;

        int mid = (l + r) / 2;
        TreeNode * root = new TreeNode(arr[mid]);
        root->left = create(l, mid - 1, arr);
        root->right = create(mid + 1, r, arr);
        return root;
    }
};
