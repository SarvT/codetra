void printCorner(Node *root)
{

// Your code goes here
queue<Node*>q;
q.push(root);
while(!q.empty())
{  
    int n=q.size();
    for(int i=0;i<n;i++)
    {
        Node* node=q.front();
        q.pop();
        if(i==0||i==n-1)
        {
            cout<<node->data<<" ";
        }
        if(node->left!=NULL)
        q.push(node->left);
        if(node->right!=NULL)
        q.push(node->right);
    }
}
}
