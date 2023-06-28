class Solution {
public:
    string getPermutation(int n, int k) {
       int f=1;
       vector<int> nr;
       for(int i=1; i<n; i++){
           f=f*i;
           nr.emplace_back(i);
       }
       nr.emplace_back(n);
       string ans="";
       k-=1;
       while(true){
           ans += to_string(nr[k/f]);
           nr.erase(nr.begin()+k/f);
           if(!nr.size()) break;
           k %=f;
           f /=nr.size();
       }
       return ans;
    }
};
