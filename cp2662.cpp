class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq; 
        map<vector<int>, int> dist;
        dist[start] = 0;
        int ans = abs(start[0] - target[0]) + abs(start[1] - target[1]);
        vector<vector<int>> filteredRoads;
        for(auto r : specialRoads){
            int a = r[0], b = r[1], c = r[2], d = r[3], cost = r[4];
            if(cost < abs(a-c) + abs(b-d)){
                filteredRoads.push_back({a,b,c,d,cost});
                dist[{c,d}] = abs(start[0] - c) + abs(start[1] - d);
            } 
        }
        pq.push({0, start[0], start[1]});


        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int mdist = it[0], x= it[1], y = it[2];

            for(auto r : filteredRoads){
                int a = r[0], b = r[1], c = r[2], d = r[3], rcost = r[4];
                if(dist[{c,d}] > mdist + abs(x-a) + abs(y-b) + rcost){
                    dist[{c,d}] = mdist + abs(x-a) + abs(y-b) + rcost;
                    pq.push({dist[{c,d}], c, d});
                }
            }
        }
        
        for(auto r : filteredRoads){
            int tx = target[0], ty = target[1];
            int a = r[0], b = r[1], c = r[2], d = r[3], cost = r[4];
            ans = min(ans, dist[{c,d}] + abs(c-tx) + abs(d-ty));
            cout<<dist[{c,d}]<<"\n";
            
        }
        return ans;
    }
};
