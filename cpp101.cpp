// Leet
class Solution {
public:
    bool traverse(TreeNode* p, TreeNode* q){
        if(!(p) && (q)) return false;
        else if(!(q) && (p)) return false;
        else if(!(p) && !(q)) return true;

        if(p->val == q->val) return traverse(p->left, q->right) && traverse(p->right, q->left);
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return traverse(root->left, root->right);
    }
};
