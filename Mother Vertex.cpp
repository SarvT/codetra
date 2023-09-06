class Solution 
{
    private:
    void dfs(int node,vector<int> &vis,int &motherVertex,vector<int> adjList[]){
        vis[node] = 1;
        for(int adjNode : adjList[node]){
            if(!vis[adjNode]) dfs(adjNode,vis,motherVertex,adjList);
        }
        motherVertex = node;
    }
public:
	int findMotherVertex(int V, vector<int>adjList[]){
	    int motherVertex = -1;
	    vector<int> vis(V,0);
	    for(int node=0;node<V;node++){
	        if(!vis[node]) dfs(node,vis,motherVertex,adjList);
	    }
	    vis = vector<int>(V,0);
	    int ans = motherVertex;
	    dfs(ans,vis,motherVertex,adjList);
	    for(int node=0;node<V;node++) if(!vis[node]) return -1;
	    return ans;
	}

};
