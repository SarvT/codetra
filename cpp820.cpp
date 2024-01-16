class Solution {
public:
    bool cmp(string &a,string &b){
        return a.length()>b.length();
    }
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(),words.end(),cmp);
        string res="";
        res=res+words[0]+"#";
        for(int i=1;i<words.size();i++){
            int pos=res.find(words[i]+"#");
            if(pos!=-1)continue;
            else res+=words[i]+"#";   
        }
        return res.length();
    }
};
