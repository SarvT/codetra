class Solution {
public:
    void rec(int n, int m, vector<vector<int>>& vis, vector<vector<char>>& grid){
        vis[n][m]=1;
        queue<pair<int,int>> q;
        q.push({n, m});
        int a=grid.size();
        int b=grid[0].size();
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i=-1; i<=1; i++){
                for(int j=-1; j<=1; j++){
                    int nrow = row+i;
                    int ncol = col+j;

                    if(nrow>=0 && nrow<a && ncol>=0 &&ncol<b &&
                    grid[nrow][ncol]=='1' && !vis[nrow][ncol]){
                        vis[nrow][ncol]=1;
                        q.push({nrow, ncol});
                    }
                }

            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> v(n, vector<int>(m, 0));
        int cnt=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!v[i][j] && grid[i][j]=='1' ){
                    cnt++;
                    rec(i, j, v, grid);
                }
            }

        }
        return cnt;
    }
};



class Solution {
public:
    bool abc(vector<vector<char>>&G, int i, int j)
    {
        if(i<0||j<0||i>=G.size()||j>=G[0].size())
            return true;        
        if (G[i][j] == '0')
            return true;        
        G[i][j]='0';
        bool p=abc(G,i+1,j), q=abc(G,i,j+1), r=abc(G,i-1,j), s=abc(G,i,j-1);
        return p && q && r && s;
    }

    int numIslands(vector<vector<char>>& grid) {
        int k=0;
        for (int i=0;i<grid.size();i++)
            for (int j=0;j<grid[0].size();j++)
                if(grid[i][j]=='1')
                {
                    if(abc(grid,i,j))
                       k++;
                }       
        return k;
    }
    
};
