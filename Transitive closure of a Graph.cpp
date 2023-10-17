class Solution{
public:
unordered_map<int,vector<int>>hmap;
void dfs(int node,vector<int>&vis){
    vis[node]=1;
    for(auto &it:hmap[node]){
        if(vis[it]==0)dfs(it,vis);
    }
}
    vector<vector<int>> transitiveClosure(int N, vector<vector<int>> graph)
    {
        // code here
        vector<vector<int>>ans(N,vector<int>(N,0));
        
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(graph[i][j]==1 and i!=j)hmap[i].push_back(j);
            }
        }
        for(int i=0;i<N;i++)dfs(i,ans[i]);
        return ans;
    }
};
