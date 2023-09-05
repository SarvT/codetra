class Solution {
  public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<pair<int,int>>edges) {
        // Code here
        vector<vector<int>> adjList(V);
        for(auto i:edges){
            adjList[i.first].emplace_back(i.second);
            adjList[i.second].emplace_back(i.first);
        }
        return adjList;
    }
};
