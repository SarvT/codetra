// worked
// both workss
//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int DivisibleByEight(string s){
        //code here
        
        if(s.length()>3){
            string str;
            str.push_back(s[s.length()-3]);
            str.push_back(s[s.length()-2]);
            str.push_back(s[s.length()-1]);
            int n = stoi(str);
            // cout<<str;
            // int n;
            // for(int i=0; i<str.length(); ++i) n = n * 10 + (str[i] - '0');
            if(n%8==0)return 1;
        } else {
            // int n;
            int n = stoi(s);
            // for(int i=0; i<s.length(); i++) n = n * 10 + (s[i] - '0');
            if(n%8==0)return 1;

        }
        return -1;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.DivisibleByEight(S)<<"\n";
    }
}
// } Driver Code Ends
