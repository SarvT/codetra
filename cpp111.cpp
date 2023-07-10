// Leet
// Not worked

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

    int leftCnt=0, rightCnt=0;
    void rec(TreeNode* root, bool isLeft, bool isRight, int level){
        if(!root){
            
            return;
        } 

        if(isLeft && !isRight) leftCnt++;
        if(isRight && !isLeft) rightCnt++;
        
        rec(root->left, true, false, level+1);
        rec(root->right, false, true, level+1);

    }
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        rec(root, true, true, 0);
        
        if(!root->left) return rightCnt;
        if(!root->right) return leftCnt;
        return (min(leftCnt, rightCnt));
    }
};


// worked
int minDepth(TreeNode* root) {
        int leftCnt=0, rightCnt=0;
        if(!root) return 0;
        leftCnt = minDepth(root->left);
        rightCnt = minDepth(root->right);
        if(root->left && root->right) return min(leftCnt+1, rightCnt+1);
        return (max(leftCnt+1, rightCnt+1));
    }
