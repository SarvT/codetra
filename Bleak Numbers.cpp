//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
	int counting_bits(int n)
	{
	    // Code here.
	    int set = 0;
        while(n)
        {
            if( (n & 1) == 1) set++;
            n>>=1;
        }
        return set;
    }
        
    int is_bleak(int n)
    {
        int useful_bits = ceil(log2(n));
        for(int i=n-1; i>= n - useful_bits; i--)
        {
            if(i + counting_bits(i) == n) return 0;
        }
        return 1;
	}
};


//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	Solution ob;
    	int ans = ob.is_bleak(n);
    	cout << ans << "\n";
    }
	return 0;
}

// } Driver Code Ends
