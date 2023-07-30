// gfg
// worked
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    int maximumNumber(int N) {
        // code here
        string sa = to_string(N);
        string ans = "";
        int flag=1;
        for(int i=0; i<sa.size(); i++){
            if(sa[i] == '7' && flag){
                ans.push_back('9');
                i++;
                flag = 0;
            }
            ans.push_back(sa[i]);
            // break;
        }
        return stoi(ans);
    }
};

