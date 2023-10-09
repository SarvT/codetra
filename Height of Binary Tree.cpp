// worked
class Solution{
    public:
    int mh=0;
    //Function to find the height of a binary tree.
    void dfs(struct Node* node, int h){
        if(!node){
            h=max(h, mh);
            return;
            
        }
        mh=max(mh, h);
        dfs(node->left, h+1);
        dfs(node->right, h+1);
    }
    int height(struct Node* node){
        // code here 
        int h=0;
        dfs(node, h+1);
        return mh;
        // dfs(node->right, h+1, mh);
    }
};
