//yes worked
//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	string removeDuplicates(string str) {
	    // code here
	    unordered_map<char, int> mp;
	    for(auto it:str) mp[it]++;
	    string sr = "";
	    for(auto it:str){
	        if(mp[it]!=0){
	            mp[it]=0;
	            sr.push_back(it);
	        }
	    }
	    return sr;
	    
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        auto ans = ob.removeDuplicates(str);

        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
