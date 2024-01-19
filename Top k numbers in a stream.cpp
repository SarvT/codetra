//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    vector<vector<int>> kTop(vector<int>& arr, int N, int K) {
        // code here
        vector<int> vec(K+1 , 0);
        vector<vector<int>> ans;
        unordered_map<int,int> mp;
        for(int i = 0 ; i < N ; i++)
        {
            vec[K] = arr[i];
            mp[arr[i]]++;
            
            int k = find(vec.begin() , vec.end()-1,arr[i])-vec.begin()-1;
            
            for(int j = k ; j>=0 ;j--){
                if(mp[vec[j]] < mp[vec[j+1]] || (mp[vec[j]] == mp[vec[j+1]] && vec[j]>vec[j+1]))swap(vec[j], vec[j+1]);
                else break;
            }
            
            vector<int> temp;
            for(int j= 0 ; j<K && vec[j]!=0; j++)temp.push_back(vec[j]);
                
            ans.push_back(temp);
            
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        
        vector<int> a(N);
        Array::input(a,N);
        
        Solution obj;
        vector<vector<int>> res = obj.kTop(a, N, K);
        
        for(auto it:res)
            Array::print(it);
        
    }
}

// } Driver Code Ends
