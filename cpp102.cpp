// Leet
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        if(!root) return ans;
        q.emplace(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> l;
            for(int i=0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                l.push_back(node->val);
            }
            ans.push_back(l);
        }
        return ans;
    }
};
