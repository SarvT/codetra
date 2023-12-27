//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> antiDiagonalPattern(vector<vector<int>> matrix) 
    {
        // Code here
        int j=0, n=matrix.size();
        vector<int> ans;
        while(j<n){
            int a=0,b=j;
            while(b>=0 and a<n) ans.push_back(matrix[a++][b--]);
            j++;
        }
        int i=1;
        while(i<n){
            int a=i,b=n-1;
            while(b>=0 and a<n) ans.push_back(matrix[a++][b--]);
            i++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> matrix;
        matrix.resize(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> ans = ob.antiDiagonalPattern(matrix);
        for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
