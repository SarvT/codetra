class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> cal(n, vector<int>(m, INT_MAX));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> miniHeap;
        miniHeap.emplace(0, 0, 0);
        cal[0][0] = 0;

        int deltaDir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while(!miniHeap.empty()){
            auto [e, x, y] = miniHeap.top();
            miniHeap.pop();

            if(e>cal[x][y]) continue;
            if(x == n-1 && y == m-1) return e;

            for(auto& dir: deltaDir){
                int nx = x+dir[0], ny=y+dir[1];
                if(nx >= 0 and nx<n and ny>=0 and ny<m){
                    int ne = max(e, abs(heights[x][y]-heights[nx][ny]));
                    if(ne<cal[nx][ny]){
                        cal[nx][ny]=ne;
                        miniHeap.emplace(ne, nx, ny);
                    }
                }
            }
        }
        return -1;
    }
};
