//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int getMaxArea(vector<int> &arr) {
        // Your code here
        int n = arr.size();
        vector<int> prevSmaller (n, 0);
        prevSmaller[0] = -1;
        stack<int> st, stk;
        st.push(0);
        for(int i = 1; i < n; i++){
            while(st.empty() == false && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(st.empty()){
                prevSmaller[i] = -1;
            }else{
                prevSmaller[i] = st.top();
            }
            st.push(i);
        }
        
        vector<int> nextSmaller (n, 0);
        nextSmaller[n - 1] = n;
        
        stk.push(n - 1);
        for(int i = n - 2; i >= 0; i--){
            while(stk.empty() == false && arr[stk.top()] >= arr[i]){
                stk.pop();
            }
            if(stk.empty()){
                nextSmaller[i] = n;
            }else{
                nextSmaller[i] = stk.top();
            }
            stk.push(i);
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans = max(ans, arr[i]*(nextSmaller[i] - prevSmaller[i] - 1));
        }
        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.getMaxArea(arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends
