//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// USer function Template for C++

class Solution {
  public:
    string removeKdigits(string S, int K) {
        int n = S.size();
        string ans;
        for(int i=0;i<n;i++){
            while(!ans.empty() && ans.back()>S[i] && K){
                ans.pop_back();
                K--;
            }
            if(S[i]!='0'||ans.size())ans.push_back(S[i]);
        }
        ans = ans.substr(0,max((int)ans.size()-K,0));
        return ans.size()?ans:"0";
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;
        Solution obj;
        cout << obj.removeKdigits(S, K) << endl;
    }
    return 0;
}

// } Driver Code Ends
