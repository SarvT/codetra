class Solution{
  public:
    void rec(Node *root, vector<Node*>& v){
        if(!root || !x) return;
        rec(root->left, v);
        v.emplace_back(root);
        rec(root->right, v);
    }
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        //Your code here
        vector<Node*> v;
        rec(root, v);
        int i=0;
        int d = x->data;
        for(auto a:v){
            if(a==NULL) cout << " -1 ";
        cout << a->data << ' ';
        }
        for(auto vt: v){
            i++;
            if(vt->data == x->data){
                if(v[i]==NULL) return nullptr;
            }
            return nullptr;
            // return v[++i];
            
        }
        return nullptr;
    }
};



// worked

if(!root || !x) return;
        Node *parent = NULL;
        while(root != x) {
            if (root->data > x->data) {
                parent = root;
                root = root->left;
            } else {
                root = root->right;
            }
        }
        if (x->right == NULL) {
            if (parent && (parent->data > x->data)) {
                return parent;
            }
            return NULL;
        }
        Node *q = x->right;
        while (q && q->left) {
            q = q->left;
        }
        return q;
