//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int evaluate(vector<string>& arr) {
        // code here
        stack<int>st;
        for(auto it:arr){
            if(it!="+" && it!="*" && it!="/" && it!="-"){
                int a = stoi(it);
                st.push(a);
            }
            else{
                int first = st.top();
                st.pop();
                int second = st.top();
                st.pop();
                if(it=="-")st.push(second-first);
                else if(it=="+")st.push(second+first);
                else if(it=="*")st.push(second*first);
                else st.push(second/first);
            }
        }
        return st.top();
    }
};


//{ Driver Code Starts.

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        vector<string> arr;
        while (ss >> str) {
            arr.push_back(str);
        }
        Solution ob;
        cout << ob.evaluate(arr) << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends
