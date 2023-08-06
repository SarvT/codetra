not worked
class Solution{
    public:
    //Complete this function
    
    vector<string> permutation(string S)
    {
        //Your code here
        int n = S.size();
        string str="";
        vector<string> ans;
        for(int i=0; i<n; i++){
            str.push_back(S[i]);
            while(j<n){
                if(i!=j){
                    str.push_back(S[j++]);
                }
                
                else j++;
            }
            ans.emplace_back(str);
            str="";
        }
        return ans;
    }
};


worked
class Solution{
    public:
    //Complete this function
    void rec(string S, int l, int n, vector<string>& ans){
        if(l == n){
            ans.emplace_back(S);
            return;
        }
        
        for(int i=l; i<n; i++){
            swap(S[i],S[l]);
            rec(S, l+1, n, ans);
            swap(S[i],S[l]);
            
        }
    }
    vector<string> permutation(string S)
    {
        //Your code here
        vector<string> ans;
        int n = S.size();
        // string str="";
        rec(S, 0, n, ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};
