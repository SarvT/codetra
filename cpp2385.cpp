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
    int amountOfTime(TreeNode* root, int start) {
        stack<TreeNode *> st;
        queue<TreeNode *> q;
        parent(root, start, st, q);

        unordered_map<int, bool> mp;
        mp.insert({start, true});
        q.push(NULL);
        int ans = 0;

        while (!q.empty()){
            TreeNode *infected = q.front();
            q.pop();
            while (infected){
                if (infected->left && mp.find(infected->left->val) == mp.end()){
                    q.push(infected->left);
                    mp.insert({infected->left->val, true});
                }
                if (infected->right && mp.find(infected->right->val) == mp.end()){
                    q.push(infected->right);
                    mp.insert({infected->right->val, true});
                }
                if (!st.empty() && mp.find(st.top()->val) == mp.end() && ((st.top()->left && st.top()->left == infected) || (st.top()->right && st.top()->right == infected))){
                    q.push(st.top());
                    mp.insert({st.top()->val, true});
                    st.pop();
                }
                infected = q.front();
                q.pop();
            }
            if (!q.empty()){
                ans++;
                q.push(NULL);
            }
        }
        return ans;
    }
    bool parent(TreeNode *root, int &start, stack<TreeNode *> &st, queue<TreeNode *> &q)
    {
        if (root && root->val == start){
            q.push(root);
            return true;
        }

        if (root){
            st.push(root);
            if (!(parent(root->left, start, st, q)) && !(parent(root->right, start, st, q))){
                st.pop();
                return false;
            }
            else return true;
        }
        return false;
    }

};
