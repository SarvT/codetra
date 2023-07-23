// Leet
// worked
class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string> res;
        int n=words.size();
        for(int i=0; i<n; i++){
            string str = "";
            for(char c:words[i]){
                if(str == "" && c == separator){
                    continue;
                }
                else if (c == separator && str!=""){
                    res.emplace_back(str);
                    str = "";
                }else if(c != separator){
                    str.push_back(c);
                } 
            }if(str!="") res.emplace_back(str);
        }
        return res;
    }
};
