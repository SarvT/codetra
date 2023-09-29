//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int dr[4]={-1, 0, 1, 0};
    int dc[4]={0, 1, 0, -1};
    int n;
    int m;
  
    void bfs(int row, int col, vector<vector<int>> &grid, 
    vector<vector<bool>>&vis){
        vis[row][col]=1;
        queue<pair<int, int>>q;
        q.push({row, col});
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0; i<4; i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && grid[nr][nc]==1){
                    vis[nr][nc]=1;
                    q.push({nr, nc});
                }
            }
        }
        return;
    }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        n=grid.size();
        m=grid[0].size();
        
        vector<vector<bool>>vis(n, vector<bool>(m, 0));
        int cnt=0;
        for(int i=0; i<n; i++){
            if(grid[i][0]==1 && vis[i][0]==0){
                bfs(i, 0, grid, vis);
            }
            if(grid[i][m-1]==1 && vis[i][m-1]==0){
                bfs(i, m-1, grid, vis);
            }
        }
        
        for(int j=0; j<m; j++){
            if(grid[0][j]==1 && vis[0][j]==0){
                bfs(0, j, grid, vis);
            }
            if(grid[n-1][j]==1 && vis[n-1][j]==0){
                bfs(n-1, j, grid, vis);
            }
        }
        
        for(int i=1; i<n-1; i++){
            for(int j=1; j<m-1; j++){
                if(grid[i][j]==1 && vis[i][j]==0){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends
