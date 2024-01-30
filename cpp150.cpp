class Solution {
public:
    int solve(int a, int b, string op){
        if(op=="+")return b+a;
        else if(op=="-")return b-a;
        else if(op=="*")return b*a;
        else return floor(b/a);
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]!="+" && tokens[i]!="-" && tokens[i]!="*" && tokens[i]!="/"){
                int x=stoi(tokens[i]);
                st.push(x);
            }else{
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                int ans=solve(a,b,tokens[i]);
                st.push(ans);
            }
        }
        return st.top();
    }
};
