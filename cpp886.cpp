// Not worked
class Solution {
public:
    // unordered_map<int, int> m;

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        // for(auto i=0; i<n; i++){
        //     for(auto j=0; j<2; j++){
        //         if(m.find(dislikes[i][j]) != m.end()) return false;
        //         else m[i] = dislikes[i][j];
        //     }
        // }

        vector<int> color(n+1,-1);
        vector<int> adj[n+1];
        for(auto i: dislikes){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        for(int i=1; i<=n; i++){
            if(color[i] == -1){
                if(cycle(i, adj, color)) return false;
            }
        }

        return true;
    }
    bool cycle(int val, vector<int> adj[], vector<int> &color){
        if(color[val] == -1) return color[val]=1;
        for(int i:adj[val]){
            if(color[i] == -1){
                color[i] = 1-color[val];
                if(cycle(i, adj, color)) return true;
            }
            else if(color[i]==color[val]) return true;
        }
        return false;

    }
};



// Worked
class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
        vector<int> color(n+1,-1);
        vector<int> adj[n+1];
        for(auto p:dislikes){
            adj[p[0]].push_back(p[1]);
            adj[p[1]].push_back(p[0]);
        }
        for(int node=1;node<=n;node++){
            if(color[node]==-1){
                if(cycle(node,adj,color))return false;
            }
        }
        return true;
    }
    bool cycle(int node,vector<int> adj[], vector<int> &color){
        if(color[node]==-1)color[node]=1;
        for(int child:adj[node]){
            if(color[child]==-1){
                color[child]=1-color[node];
                if(cycle(child,adj,color))return true;
            }
            else if(color[child]==color[node])return true;
        }
        return false;
    }
};
