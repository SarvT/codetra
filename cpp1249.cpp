class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int cnt=0;
    
        string temp="";
        for(auto ch:s){
            if(ch==')'&&cnt==0){
                cnt=0;
                continue;

            }
            if(ch=='(') cnt++;
            if(ch==')') cnt--;
            temp+=ch;
        }
        
        cnt=0;
        for(auto c:temp){
            if(c=='(') cnt++;
            if(c==')') cnt--;
        }
        if(cnt==0) return temp;
        string rev="";
      
        for(int i=temp.length()-1;i>=0;i--){
            if(temp[i]=='('&&cnt>0){
                cnt--;
                continue;
            }
            rev+=temp[i];


        }
        reverse(rev.begin(),rev.end());
        
        return rev;
    }
};
