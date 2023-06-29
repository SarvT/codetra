// Not worked
class Solution {
public:
    TreeNode* rec(TreeNode* root, int k){
        if(!root) return NULL;
        TreeNode* s=rec(root->left, k);
        if(s!=NULL) return s;
        k--;
        if(k==0) return root;
        return(rec(root->right, k));
    }
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return NULL;
        TreeNode* sol = rec(root, k);
        if(!sol) return NULL;
        return sol->val;
    }
};

// Worked
class Solution {
public:
    int rec(TreeNode* root, int &i, int k){
        if(root==NULL)return -1;
        int left=rec(root->left,i,k);
        if(left!=-1)return left;
        i++;
        if(i==k)return root->val;
        return rec(root->right,i,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        int i=0;
        return rec(root, i, k);
    }
};
