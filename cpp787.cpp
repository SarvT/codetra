class Solution {
public:
const int N = 1000;
    vector<pair<int, int>> res;
    int Dijkstra(vector<pair<int, int>> graph[], int src, int dst, int k){
        vector<bool> vist(1000, false);
        vector<int> dist(1000, 1e9);
        queue<pair<int, pair<int, int>>> pq;
        pq.push({0, {0, src}});
        dist[src] = 0;
        while (!pq.empty()){
            auto ii = pq.front();
            pq.pop();
            int jn = ii.first;
            int dist_v = ii.second.first;
            int node = ii.second.second;
            if(node == dst && jn == k + 1){
                res.push_back({jn, dist_v});
                break;
            }

            if(jn > k + 1)continue;
            for(auto ii : graph[node])
            {
                int child_v = ii.first;
                int wt = ii.second;
                if((dist_v + wt < dist[child_v]) && jn < k + 1){
                    dist[child_v] = dist_v + wt;
                    pq.push({jn + 1, {dist[child_v], child_v}});
                }
            }
        }
        for(auto ii : res)cout << ii.first << " " << ii.second << endl;
        if(dist[dst] == 1e9)return -1;
        return dist[dst];
    }
        
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int kk = flights.size();
        vector<pair<int, int>> graph[N];
        for (int i = 0; i < kk; i++)graph[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        return Dijkstra(graph, src, dst, k);   
    }
};
