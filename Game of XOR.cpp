//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int gameOfXor(int N , int A[]) {
        // code here
        int sol=0;
        for(int b=1;b!=(1<<31);b<<=1){
            int temp=0,a=0,c=0,d;
            for(int i=0;i<N;i++){
                if(A[i]&b) a++;
                if(a&1) c++;
            }
            d=N-c;
            for(int i=0;i<N;i++){
                temp^=(c&1);
                if(A[i]&b){
                    c--;
                    swap(c,d);
                }
                else d--;
            }
            sol+=temp*b;
        }
        return sol;

    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int A[N];
        for(int i=0 ; i<N ; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.gameOfXor(N,A) << endl;
    }
    return 0;
}
// } Driver Code Ends
