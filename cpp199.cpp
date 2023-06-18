// Leet
// Not worked
class Solution {
public:
    void traverse(TreeNode* root, vector<int> &sol){
        if(!root) return;
        sol.push_back(root->val);
        traverse(root->right, sol);
        return;
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v1;
        traverse(root, v1);
        return v1;
    }
};

// Worked -1
class Solution {
public:
    map<int,int> m;
    void traverse(TreeNode* root, int l){
        if(!root) return;
        if(m.find(l)==m.end()) m[l] = root->val;
        traverse(root->right, l+1);
        traverse(root->left, l+1);
        return;
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v1;
        if(!root) return v1;
        traverse(root, 1);
        for(auto i:m) v1.push_back(i.second);
        return v1;
    }
};
