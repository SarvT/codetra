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
int cnt = 0;
vector<int> dfs(TreeNode* root,int distance) {

        if(!root){
            vector<int> dis(11,0);
            return dis;
        }

        if(!root->left && !root->right){
            vector<int> dis(11,0);
            dis[1]++;
            return dis;
        }

        vector<int> left = dfs(root->left,distance);
        vector<int> right = dfs(root->right,distance);

        cnt += isLeaf(left,right,distance);

        vector<int> mergedVector = mergerFunc(left,right);

        return mergedVector;
    }
    vector<int> mergerFunc(vector<int> left,vector<int> right){

        vector<int> ans(11,0);

        for(int i = 9; i >= 0 ;i--){
            ans[i+1] = left[i] + right[i];
        }

        return ans;
    }
    int isLeaf(vector<int> left,vector<int> right,int distance){
       int cnt = 0; 
        for(int i = 0; i < 11 ; i++) {
            for(int j = 0; j < 11 ; j++){
                if(i+j <= distance){
                    cnt += left[i]*right[j];
                }
            }
        }

        return cnt;
    }
    int countPairs(TreeNode* root, int distance) {
        dfs(root,distance);
        return cnt;
    }
};
