class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if (source == destination)return true;
        vector<vector<int>> adj(n);
        
        for (vector<int> v : edges) {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }

        stack<int> s;
        unordered_set<int> seen;

        s.push(source);
        seen.insert(source);

        while (!s.empty()) {
            int last = s.top();
            s.pop();
            for (int i : adj[last]) {
                if (i == destination)return true;
                if (seen.find(i) == seen.end()) {
                    s.push(i);
                    seen.insert(i);
                }
            }
        }
        return false;
    }
};
