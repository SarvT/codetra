// not worked
class Solution{
  public:
  void call(string s, unordered_set<string>& st, int n, int l, string str){
      if(l >= n) {
          st.insert(str);
          return;
      }
      
      for(int i=l; i<n; i++){
          str.push_back(s[i]);
          call(s, st, n, i, str);
          str.pop_back();
      }
  }
	int distinctSubsequences(string s)
	{
	    // Your code goes here
	    unordered_set<string> st;
	    string str;
	    int n=s.size();
        call(s, st, n, 0, str);
	    return st.size()-1;
	    
	}
};

// worked
class Solution{
  public:
	int distinctSubsequences(string s)
	{
	    // Your code goes here
	     int ans=1,m=1e9+7;
        int mp[26]={0};
        for(char c:s){
            int repeating_seq = mp[c-'a'];  
            mp[c-'a']=ans;               
            ans=(1LL*ans*2 - repeating_seq+m)%m;  
        }
        return ans;
	    
	}
};
