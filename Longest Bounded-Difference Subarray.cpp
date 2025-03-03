//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        // code here
        int n = arr.size(), start = -1, end = -1, maxi = 0;
        
        multiset<int> st;
        
        for(int i = 0, j = 0; i < n; i++) {
            st.insert(arr[i]);
            while(st.size() > 1 && (*st.rbegin() - *st.begin()) > x) {
                st.erase(st.find(arr[j++]));
            }
            int len = (i - j + 1);
            if(len > maxi) {
                maxi = len;
                start = j;
                end = i;
            }
        }
        
        vector<int> ans;
        while(start <= end) ans.push_back(arr[start++]);
        
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
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        vector<int> ans = ob.longestSubarray(arr, k);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
