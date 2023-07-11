// Leet
// not worked
class Solution {
public:
    void rec(TreeNode* root, TreeNode* target, int k){
        if(root->val == target) return;

        if(!root) return;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> sol;
    }
};

// worked
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    void rec(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& track, TreeNode* target){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            if(curr->left){
                track[curr->left] = curr;
                q.push(curr->left);
            }
            if(curr->right){
                track[curr->right] = curr;
                q.push(curr->right);
            }

        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> track;
        rec(root, track, target);

        unordered_map<TreeNode*, bool> vis;

        queue<TreeNode*> q;
        q.push(target);
        vis[target] = true;
        int level = 0;
        while(!q.empty()){
            int size = q.size();
            if(level++ == k) break;
            for(int i=0; i<size; i++){
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left && !vis[curr->left]){
                    q.push(curr->left);
                    vis[curr->left] = true;
                }
                if(curr->right && !vis[curr->right]){
                    q.push(curr->right);
                    vis[curr->right] = true;
                }
                if(track[curr] && !vis[track[curr]]){
                    q.push(track[curr]);
                    vis[track[curr]] = true;
                }
            }
        }
        vector<int> res;
        while(!q.empty()){
            TreeNode* current = q.front();
            q.pop();
            res.emplace_back(current->val);
        }
        return res;

    }
};
