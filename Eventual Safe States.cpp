not worked
class Solution {
  public:
  bool hasSingle(int& arr[]){
      return (arr.size()==1);
  }
  bool isTerm(int& arr[]){
      return (arr.size()==0);
  }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        for(auto it: adj){
            
        }
    }
};



worked
class Solution {
  public:
  bool check(int node,vector<int> adj[],vector<int> &vis){
        if(vis[node]) return false;
        vis[node] = 1;
        for(auto it : adj[node]){
            if(check(it,adj,vis)==false) return false;
        }
        vis[node]=0;
        return true;
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<int> ans;
        vector<int> vis(V,0);
        for(int i=0; i<V; i++){
            if(check(i,adj,vis)) ans.push_back(i);
        }
            
        return ans;
    }
};
