// Leet
// Not worked
class Solution {
public:
    bool traverse(TreeNode* root, int prev, int l, int main){
        if(!root) return true;
        if(l==1 && root->val>=prev && root->val>=main) return false;
        if(l==0 && root->val<=prev && root->val<=main) return false;
        return (traverse(root->left, root->val, 1, main) && traverse(root->right, root->val, 0, main));
    }
    bool isValidBST(TreeNode* root) {
        return (traverse(root->left, root->val, 1, root->val) && traverse(root->right, root->val, 0, root->val));
    }
};

// Worked
class Solution {
public:
    bool traverse(TreeNode* root, long long l, long long r){
        if(!root) return true;
        if(root->val<r && root->val>l) return traverse(root->left, l, root->val) && traverse(root->right, root->val, r);
        else return false;
    }
    bool isValidBST(TreeNode* root) {
        return (traverse(root, LLONG_MIN, LLONG_MAX));
    }
};
