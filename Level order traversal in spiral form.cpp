gfg
not worked
vector<int> findSpiral(Node *root)
{
    //Your code here
    queue<Node*> q;
    vector<int> ans;
    q.push(root);
    int i=0;
    while(!q.empty()){
        Node *tmp = q.front();
        q.pop();
        ans.push_back(tmp->data);
        if(i==0){
            i=1;
            q.push(tmp->left);
            q.push(tmp->right);
        }
        else if(i==1){
            i=0;
            q.push(tmp->right);
            q.push(tmp->left);
            
        }
    }
    return ans;
}


worked
vector<int> findSpiral(Node *root)
{
    //Your code here
     bool flag=true;
    queue<Node*> q;
    vector<int> v;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        vector<int> v1;
        for(int i=0;i<n;i++){
            Node *temp=q.front();
            q.pop();
            v1.push_back(temp->data);
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
        if(!flag){
            for(int i=0;i<v1.size();i++){
                v.push_back(v1[i]);
            }
            flag=true;
        }
        else{
            for(int i=v1.size()-1;i>=0;i--){
                v.push_back(v1[i]);
            }
            flag=false;
        }
    }
    return v;
}
