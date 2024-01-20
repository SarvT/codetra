class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int res=0, n = arr.size(), MOD=1e9+7;
        vector<int> left(n,-1), right(n,n);
        stack<int> stk;
        for(int i=0; i<n; i++){
            while(stk.size() && arr[i] < arr[stk.top()]) stk.pop();
            if(stk.size()) left[i] = i - stk.top();
            else left[i] = i+1;
            stk.push(i);
        }
        while(stk.size(
            
        )) stk.pop();
        for(int i=n-1; i>=0; i--){
            while(stk.size() && arr[i] <= arr[stk.top()]) stk.pop();
            if(stk.size()) right[i] = stk.top() - i;
            else right[i] = n - i;
            stk.push(i);
        }
        for(int i=0; i<n; i++){
            long long prod = (left[i]*right[i])%MOD;
            prod = (prod*arr[i])%MOD;
            res = (res + prod)%MOD;
        }
        
        return res%MOD;
    }
};
