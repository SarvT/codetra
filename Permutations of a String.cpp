//not worked
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  void rec(string s, int st, int n, set<string> set){
      if(st>=n) return;
      string str = "";
      str += s[st];
      for(int i=0; i<n; i++){
          if(i==st) continue;
          str += s[i];
      }
      cout<<str<<endl;
      set.insert(str);
      return;
  }
    vector<string> findPermutation(string &s) {
        // Code here there
        set<string> set;
        int n=s.size();
        for(int i=0; i<n; i++)rec(s, i, n, set);
        vector<string> vec;
        for(auto it:set) vec.emplace_back(it);
        return vec;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.findPermutation(S);
        sort(ans.begin(), ans.end());
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends


//worked
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  void rec(string &s, vector<string> &vec, int index) {
        if (index == s.size()) {
            vec.push_back(s);
            return;
        }

        unordered_set<char> seen;
        for (int i = index; i < s.size(); i++) {
            if (seen.find(s[i]) != seen.end()) {
                continue;
            }
            seen.insert(s[i]);
            swap(s[i], s[index]);
            rec(s, vec, index + 1);
            swap(s[i], s[index]);
        }
    }
    vector<string> findPermutation(string &s) {
        // Code here there
        vector<string> vec;
        rec(s, vec, 0);
        return vec;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.findPermutation(S);
        sort(ans.begin(), ans.end());
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends
