//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if two strings are rotations of each other or not.
    bool areRotations(string s1,string s2)
    {
        // Your code here
        if(s1 == s2) return true;
        
        for (int i = 0; i < s1.size()-1; ++i)
        {
        	char lastCharacter = s1[s1.size()-1];
        	s1.pop_back();
        	s1 = lastCharacter + s1;

        	if(s1 == s2) return true;
        }

        return false; 
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s1;
        string s2;
        cin>>s1>>s2;
        Solution obj;
        cout<<obj.areRotations(s1,s2)<<endl;

    }
    return 0;
}

// } Driver Code Ends
