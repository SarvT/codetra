//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        // code here
        unordered_map<char,int>mp;
       for(int i=0;i<s.size();i++)mp[s[i]]++;
       vector<int>vec;
       int sum=0;
       for(auto it:mp)vec.push_back(it.second);
       sort(vec.begin(),vec.end());
       for(int i=0;i<k;i++){
           int s=vec.size();
           vec[s-1]=vec[s-1]-1;
           sort(vec.begin(),vec.end());
       }
       for(int i=0;i<vec.size();i++)sum+=vec[i]*vec[i];
       return sum;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
