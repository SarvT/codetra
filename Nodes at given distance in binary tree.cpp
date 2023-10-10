class Solution
{
private:

public:
unordered_map<int,vector<int>>tr;
    
    void inorder(Node *r){
        if(!r)return;
        if(r->left){
            tr[r->data].push_back(r->left->data);
            tr[r->left->data].push_back(r->data);
            inorder(r->left);
        }
        if(r->right){
            tr[r->data].push_back(r->right->data);
            tr[r->right->data].push_back(r->data);
            inorder(r->right);
        }
    }
    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        // return the sorted vector of all nodes at k dist
                tr.clear();         // Map is not clearing automatically so doing manually.
        inorder(root);
        vector<int>ans;
        
        unordered_map<int,int>vis;
        queue<int>q;
        q.push(target);         vis[target]=true;
        int level=1;
        
        while(!q.empty()){
            int si=q.size();
            while(si--){
                int node=q.front();    q.pop();
                vis[node]=true;
                for(auto c:tr[node]){
                    if(vis.count(c))continue;
                    if(level==k)ans.push_back(c);
                    else q.push(c);
                }
            }
            if(level==k)break;
            level++;
        }
        
        sort(begin(ans),end(ans));
        return ans;

    }
};
