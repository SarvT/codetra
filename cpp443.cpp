Leet
Not worked
class Solution {
public:
    void rec(vector<char>& chars, string s, int index, int cnt){
        int n=chars.size();
        if(index == n-1) return;

        rec(chars, s, index+1, cnt);
    }
    int compress(vector<char>& chars) {
        int cnt=0;
        string s;
        for(int i=1; i<chars.size()-1; i++){
        if(chars[i] == chars[i-1]) cnt++;
        else if(chars[i] != chars[i-1]){
            if(cnt == 0)
                s.push_back(chars[i]);
            else{
                s.push_back(chars[i]);
                s.push_back(cnt);
                cnt=0;
            }
        }
        //     if(chars[i] == chars[i+1]){
        //         cnt++;
        //     }
        //     else if(cnt==0){
        //         s.push_back(chars[i]);
        //     }
        //     else {
        //         s.push_back(chars[i]);
        //         s.push_back(cnt);
        //         cnt=0;
        //     }
        }

        // rec(chars, s, 1, cnt+1);
        return s.size();
    }
};

Worked
class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0, res = 0;
        while (i < chars.size()) {
            int groupLength = 1;
            while (i + groupLength < chars.size() && chars[i + groupLength] == chars[i]) {
                groupLength++;
            }
            chars[res++] = chars[i];
            if (groupLength > 1) {
                for (char c : to_string(groupLength)) {
                    chars[res++] = c;
                }
            }
            i += groupLength;
        }
        return res;
    }
};
