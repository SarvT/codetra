//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	vector<int> generateNextPalindrome(int num[], int n) {
	    // code here
	    vector<int> arr(num,num+n);
        int mid = (n+1)/2;
        bool flag = true;
        for(int i=mid;i<n;i++)
        {
            if(arr[i]==arr[n-i-1]) continue;
            if(arr[i]<arr[n-i-1]) flag = false;
            if(arr[i]>arr[n-i-1]) flag = true;
            break;
        }
        if(flag)
        {
            int carry = 1;
            for(int i=mid-1;i>=0 && carry==1;i--)
            {
                arr[i] = (arr[i]==9? 0:arr[i]+carry--);
            }
            if(carry){
                vector<int> res;
                res.push_back(1);
                for(int i=1;i<n;i++) res.push_back(0);
                res.push_back(1);
                return res;
            }
        }
        for(int i=mid-1;i>=0;i--)
        {
            arr[n-i-1]=arr[i];
        }
        return arr;
	}

};

//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int num[n];
        for (int i = 0; i < n; i++) {
            cin >> num[i];
        }
        Solution ob;
        auto ans = ob.generateNextPalindrome(num, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
