// Leet
// worked
class Solution {
public:
    bool dfs(int node, int col, vector<int>& vis, vector<vector<int>>& graph){
        vis[node] = col;
        for(auto idx: graph[node]){
            if(vis[idx] == -1){
                if(dfs(idx, !col, vis, graph) == false) return false;
            }
                else if(vis[idx] == col) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, -1);
        for (int i=0; i< n; i++){
            if(vis[i]==-1){
                if(dfs(i, 0, vis, graph) == false) return false;

            }
        }
        return true;
    }
};
