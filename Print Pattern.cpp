// not worked
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> pattern(int N){
        // code here
        if(N==0) return {0};
        vector<int> ans;
        while(N>0){
            ans.emplace_back(N);
            N = N-5;
        }
        while(N!=ans[0]){
            ans.emplace_back(N);
            N = N+5;
        }
        ans.emplace_back(N);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> ans = ob.pattern(N);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends



// worked
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void rec(int N, vector<int> &res){
        if(N>0){
            res.push_back(N);
            rec(N-5, res);
        }
        res.push_back(N);
    }
    vector<int> pattern(int N){
        // code here
        vector<int> res;
        rec(N, res);
        return res;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> ans = ob.pattern(N);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends
