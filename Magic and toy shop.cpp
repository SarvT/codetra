//{ Driver Code Starts
#include "bits/stdc++.h"
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
public:
    int minimumMagic(int n, int m, vector<int> &price, vector<int> &magical_price)
    {
        int cnt=0, calc=0, mini=0;
        int sumPrice = accumulate(price.begin(), price.end());
        int sumMagic = accumulate(magical_price.begin(), magical_price.end());
        if(sumMagic>m) return -1;
        for(int i=0; i<n; i++){
            if(sumPrice == m) return cnt;
            else{
                m=m-sumMagic[i];
                sumPrice=sumPrice-price[i];
                cnt++;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<int>price(n),magical_price(n);
        for(int i=0;i<n;i++)
            cin>>price[i];
        for(int i=0;i<n;i++)
            cin>>magical_price[i];
        Solution ob;
        int ans=ob.minimumMagic(n,m,price,magical_price);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends
