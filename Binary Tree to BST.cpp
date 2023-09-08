class Solution{
    private:
    void pre(Node* root, priority_queue<int>& q){
        if (!root) return;
        
        q.push(root->data);
        pre(root->left, q);
        pre(root->right, q);
    }
    
    void ino(Node* root, priority_queue<int>& q){
        if(!root) return;
        
        ino(root->right, q);
        root->data = q.top();
        q.pop();
        ino(root->left, q);
        
    }
  public:
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    Node *binaryTreeToBST (Node *root)
    {
        //Your code goes here
        priority_queue<int> q;
        pre(root, q);
        ino(root, q);
        return root;
    }
};
