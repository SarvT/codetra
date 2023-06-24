// Leet
// Not worked
class Solution {
public:
    void nCopy(Node* node, Node* res, vector<int> &vis){
        res->val = node->val;
        for(auto it: node->neighbors){
            if(!vis[node->val]) nCopy(it, res, vis);
        }
        

    }
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        Node* res;
        vector<int> vis = {0};
        nCopy(node, res, vis);
        // while(node!=NULL){
        //     // queue

        //     res->val = node->val;
        //     res->val = node->val;
        // }
        return res;
    }
};


// Worked
class Solution {
public:
    unordered_map<Node* , Node*> mp;
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        if(mp.find(node) == mp.end())
        {
            mp[node] = new Node(node -> val, {});
            for(auto adj: node -> neighbors)
                mp[node] -> neighbors.push_back(cloneGraph(adj));
        }
        return mp[node];
    }
};
