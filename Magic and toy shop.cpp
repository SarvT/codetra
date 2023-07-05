Geek goes to a toy shop having N toys, the prices of these toys are given as price array. He wants to buy all the N toys, but he has only M rupees to spend. He has a magical Trident which reduces the price of each toy. This reduced price for each toy is given in magical_price array. That is for ith toy (0<i<N-1) price[i] is the original price and magical_price[i] is the price after applying magic. Since applying magic reduces the power of Trident, he wants to apply it as minimum times as possible.

Find the minimum number of toys on which he should apply this magic so as to buy all the N toys for atmost M rupees. If it is not possible for Geek to buy the toys even after applying the magic on all the toys the return -1.


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
