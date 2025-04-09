vector<int> adj[V];
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> visited(V, false);
        vector<int> disc(V, -1), low(V, -1), isAP(V, 0);
        int timer = 0;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, -1, adj, visited, disc, low, isAP, timer);
            }
        }

        vector<int> res;
        for (int i = 0; i < V; i++) {
            if (isAP[i]) res.push_back(i);
        }

        if (res.empty()) return {-1};
        return res;
