class Solution{
 private:
    void solve(Node* root , int x , int& ans){
        // base case
        if(root == NULL) return;
        
        if(root->data == x){
            ans = root->data;
            return;
        }
        
        if(root->data < x) ans = max(ans , root->data);
        
        if(root->data < x) solve(root->right , x , ans);
        if(root->data > x) solve(root->left , x , ans);
    }
public:
    int floor(Node* root, int x) {
        // Code here
        if(root == NULL) return -1;
        
        int ans = -1;
        solve(root , x, ans);
        
        return ans;
    }
};
