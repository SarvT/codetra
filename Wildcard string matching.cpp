//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution{
    public:
    bool check(string &wild, string &text, int i, int j) {
        if(i < 0 and j < 0) return true;
        if(j>=0 and i<0) return false;
        
        if(i >= 0 and j<0) {
            for(int x = 0;x<=i;x++) {
                if(wild[x] != '*') return false;
            }   
            return true;
        }
        
        if((wild[i] == text[j]) or (wild[i] == '?')) 
        return check(wild, text, i-1, j-1);
        
        if(wild[i] == '*') {
            return (check(wild, text, i-1, j) or check(wild, text, i, j-1));
        }
        else return false;
    }
    bool match(string wild, string pattern)
    {
        // code here
        int n = wild.size();
        int m = pattern.size();
        return check(wild, pattern, n-1, m-1);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        string wild, pattern;
        cin>>wild>>pattern;
        
        Solution ob;
        bool x=ob.match(wild, pattern);
        if(x)
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
    return 0;
}
// } Driver Code Ends
