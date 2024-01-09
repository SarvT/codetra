//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    vector <int> prefix_function (string s) {
            
            int N = s.size();
            
            vector <int> KMP (N, 0);
            
            for (int i=1; i < N; ++i) {
                
                int j = KMP[i-1];
                
                while (j > 0 && s[j] != s[i]) 
                    j = KMP[j-1];
                    
                if (s[i] == s[j])
                    j++;
                
                KMP[i] = j;
            }
            
            return KMP;
        }
        vector <int> search(string pat, string txt)
        {
            //code here
            string look = pat + '?' + txt;
            
            vector <int> KMP = prefix_function(look);
            vector <int> ans;
            
            int start = 2 * (pat.size());
            
            for (int i = start; i < look.size(); ++i) {
                if (KMP[i] == pat.size())ans.push_back(i - start + 1); 
            }
            
            return ans;
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        if (res.size()==0)
            cout<<-1<<endl;
        else {
            for (int i : res) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends
