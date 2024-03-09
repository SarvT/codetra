// TLE - partially worked
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    char nthCharacter(string s, int r, int n) {
        //code here
        string ne = "", str;
        for(auto it:s) ne.push_back(it);
        for(int i=0; i<r; i++){
            str = "";
            for(int it=0; it<ne.size(); it++){
                if(ne[it] == '0'){
                    str.push_back('0');  
                    str.push_back('1');  
                } 
                else if(ne[it] == '1') {
                    str.push_back('1');
                    str.push_back('0');
                    
                }
            }
            ne = "";
            for(auto it:str) ne.push_back(it);
        }
        return str[n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, N;
        string S;
        cin >> S >> R >> N;
        Solution ob;
        cout << ob.nthCharacter(S, R, N) << endl;
    }
    return 0;
}
// } Driver Code Ends



// worked
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    char nthCharacter(string s, int r, int n) {
        //code here
        string str, t = s;
        while(r--){
            str="";
            for(auto i:s){
                if(i=='0') str+="01";
                else str+="10";
                if(str.size()>= t.size()) break;
            }
            s=str;
        }
        return s[n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, N;
        string S;
        cin >> S >> R >> N;
        Solution ob;
        cout << ob.nthCharacter(S, R, N) << endl;
    }
    return 0;
}
// } Driver Code Ends
