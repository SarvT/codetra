// Leet
class Solution {
public:
    bool traverse(TreeNode* root, TreeNode* p, vector<TreeNode*> &sol){
        if(!root) return false;
        sol.push_back(root);
        if(root == p) return true;
        if((traverse(root->left, p, sol)) || (traverse(root->right, p, sol)))return true;
        sol.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans;
        if(!root) return ans;
        vector<TreeNode*> v1;
        traverse(root, p, v1);
        vector<TreeNode*> v2;
        traverse(root, q, v2);
        int i=0, j=0;
        while(i<v1.size() && j<v2.size()){
            if(v1[i] == v2[j]) ans = v1[i];
            else return ans;
            i++;
            j++; 
        }
        return ans;
    }
};
