// worked partially
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
        unordered_map<int, int>mp;
    void bfs(TreeNode* root){
        if(!root)return;
        queue<pair<int, TreeNode*>> q;
        int lvl=0;
        q.push({lvl, root});
        mp[lvl]++;
        while (!q.empty()) {
            lvl++;
            mp[q.front().first]++;
            TreeNode* current = q.front().second;
            // int curr = q.front().second;
            q.pop();
            if (current->left) q.push({lvl, current->left});
            if (current->right) q.push({lvl, current->right});
        }
        
    }
    bool isEvenOddTree(TreeNode* root) {
        if(!(root->left) && !(root->right)) return true;
        bfs(root);
        for(auto it:mp) if(mp[it.second]%2!=0)return true;
        return false;
    }
};




// worked
 queue<TreeNode*> q;
        q.push(root);
        bool lvl=0;
        while(!q.empty()){
            int sz=q.size(),prev=-1;
            for(int i=0;i<sz;i++){
                TreeNode* it=q.front();
                int curr=it->val;
                q.pop();
                if(prev==-1){
                    if(lvl&&(curr&1))return false;
                    else if(!lvl&&!(curr&1))return false;
                    else prev=curr;
                }
                else{
                    if(lvl&&((curr&1)||curr>=prev))return false;
                    else if(!lvl&&(!(curr&1)||curr<=prev))return false;
                    else prev=curr;
                }
                if(it->left)q.push(it->left);
                if(it->right)q.push(it->right);
            }
            lvl=!lvl;
        }
        return true;
