class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        for(auto ch: s){
            if(ch==']'){
                string stringtorepeat="";
                while(!st.empty()&& st.top()!="["){
                    string top=st.top();
                    stringtorepeat+=top;
                    st.pop();
                }
                st.pop();
                string num="";
                while(!st.empty() && isdigit(st.top()[0])){
                    string top=st.top();
                    num+=st.top();
                    st.pop();
                }
                reverse(num.begin(),num.end());
                int n=stoi(num);
             
                string currdecode="";
                while(n--) currdecode+=stringtorepeat;
                st.push(currdecode);
            }
            else 
            {
                string temp(1,ch);
                st.push(temp);
            }
        }
                string ans="";
                while(!st.empty()){
                    ans+=st.top();
                    st.pop();
                }
                reverse(ans.begin(),ans.end());
                return ans;
    }
};
