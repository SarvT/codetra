class Solution
{
    private:
        void helper(Node* node, int data){
            if(!node) node = new Node(data);
            else{
            if(node->data > data){
                if(!node->left) node->left = new Node(data);
                else helper(node->left, data);
            }
            if(node->data < data){
                if(!node->right) node->right = new Node(data);
                else helper(node->right, data);
            }
        }
    }
    public:
        Node* insert(Node* node, int data) {
        
            // Your code goes here
            helper(node, data);
            return node;
            
    }

};
