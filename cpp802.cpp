// Leet
// worked
class Solution {
public:

    bool dfs(int node, vector<vector<int>>& graph, vector<int>& vis, vector<int>& pathVis, vector<int>& safe){
        vis[node] = 1;
        pathVis[node] = 1;
        safe[node] = 0;
        for(auto idx: graph[node]){
            if(!vis[idx]){

            if(dfs(idx, graph, vis, pathVis, safe) == true)
            {
                safe[node] = 0;
                return true;
            }
            }
            else if(pathVis[idx])
            {

                safe[node] = 0;
                return true;
            }

        }   
        safe[node] = 1;
        pathVis[node] = 0;
        return false; 
        }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis (n+1, 0);
        vector<int> pathVis (n+1, 0);
        vector<int> safe (n+1, 0);
        vector<int> safeNodes;
        for(int i=0; i<n; i++){
            if(!vis[i]) dfs(i, graph, vis, pathVis, safe);
        }
        for(int i=0; i<n; i++){
            if(safe[i] == 1) safeNodes.push_back(i);
        }
        return safeNodes;
    }
};
