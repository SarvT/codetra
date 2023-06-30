// Leet
// Worked
class Solution {
public:
    map<int, int> m;
    void traverse(TreeNode* node, int l, vector<int>& v){
        if(!node) return;
        if(l == v.size()) v.emplace_back(node->val);
        else v[l] += node->val;
        traverse(node->left, l+1, v);
        traverse(node->right, l+1, v);
    }
    int maxLevelSum(TreeNode* root) {
        vector<int> v;
        traverse(root, 0, v);
        int maxi = INT_MIN, ans=0;

        for(int i=0; i<v.size(); i++){
            if(maxi<v[i]){
                maxi = v[i];
                ans = i+1;
            }
        }
        return ans;
    }
};
