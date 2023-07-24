// gfg
// not worked
void rec(Node *root, vector<int>& ans, bool l){
        if(root!=NULL && l==true) ans.emplace_back(root->data);
        if(!root) return;
        rec(root->right, ans, true);
        rec(root->left, ans, false);
    }
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
       // Your Code here
       vector<int> ans;
       if(!root) return ans;
       rec(root, ans, true);
       
       return ans;
    }



// worked
void rec(Node *root, vector<int>& ans, int l){
        if(!root) return;
        if(l==ans.size()) ans.emplace_back(root->data);
        rec(root->right, ans, l+1);
        rec(root->left, ans, l+1);
    }
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
       // Your Code here
       vector<int> ans;
       if(!root) return ans;
       rec(root, ans, 0);
       
       return ans;
    }
