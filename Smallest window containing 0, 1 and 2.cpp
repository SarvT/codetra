//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int findMinLength(int i,int minLength,int zero,int one, int two) {
        return min(minLength, (i - min(min(zero,one),two) + 1) );
    }
    int smallestSubstring(string S) {
        // Code here
        vector<int> vec(3, -1);
        int mini = INT_MAX;
        
        for(int i = 0; i < S.size(); i++) {
            if(S[i] == '0') vec[0] = i;
            else if(S[i] == '1') vec[1] = i;
            else vec[2] = i;
            
            if(vec[0] != -1 && vec[1] != -1 && vec[2] != -1)
                mini = findMinLength(i, mini, vec[0], vec[1], vec[2]);
        }
        
        return (mini != INT_MAX) ? mini : -1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}
// } Driver Code Ends
