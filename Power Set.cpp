//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	    vector<string >v;
        void solver(int ind,string p,string s){
            if(ind>=s.size()){if(p!="")v.push_back(p);return;}
            solver(ind+1,p+s[ind],s);
            solver(ind+1,p,s);
        }
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    string p="";
            solver(0,p,s);
            sort(v.begin(),v.end());
            return v;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends
