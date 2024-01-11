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
int ans=0;
    void dfs(TreeNode* par,int mx,int mn){
        if(par==nullptr) return;
        int val=par->val;
        mx=max(mx,val);
        mn=min(mn,val);
        
        ans=max(ans,mx-mn);
                
        dfs(par->left,mx,mn);
        dfs(par->right,mx,mn);
    }
    int maxAncestorDiff(TreeNode* root) {
        if(root==nullptr) return 0;
        dfs(root,root->val,root->val);
        return ans;
    }
};
