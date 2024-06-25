// working
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<int>> rotateMatrix(int k, vector<vector<int>> mat) {
        // code here
        int z=mat.size(), d=mat[0].size();
        vector<vector<int>> sol(z, (d, 0));
        for(int x=0; x<mat.size(); x++){
            int j=0;
            int i=0;
            while(i<mat[x].size()){
                if((i+k)>=mat[x].size()){
                    if(j<mat[x].size()) {
                        i=0;
                        while(j<mat[x].size() && i<mat[x].size()){
                            sol[x].push_back(mat[x][i]);
                            i++;
                            j++;
                        }
                    }
                }
                else{
                    i+=k;
                    sol[x].push_back(mat[x][i]);
                    
                }
                
                
            }
        }
        return sol;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];
        Solution ob;
        vector<vector<int>> ans = ob.rotateMatrix(k, mat);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cout << ans[i][j] << " ";
            cout << "\n";
        }
    }
}

// } Driver Code Ends



















//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<int>> rotateMatrix(int k, vector<vector<int>> mat) {
        // code here
        for(int i=0;i<mat.size();i++){
            int t=0;
            while (t!=k){
                mat[i].push_back(mat[i][t]);
                t++;
            }
            auto it1 = mat[i].begin();
            auto it2 = mat[i].begin()+k;
            mat[i].erase(it1,it2);
        }
        return mat;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];
        Solution ob;
        vector<vector<int>> ans = ob.rotateMatrix(k, mat);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cout << ans[i][j] << " ";
            cout << "\n";
        }
    }
}

// } Driver Code Ends
