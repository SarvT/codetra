class Solution {
private:
    int digit(int n){
        if(n >= 10000) return 5;
        else if(n >= 1000) return 4;
        else if(n >= 100) return 3;
        else if(n >= 10) return 2;
        else return 1;
    }
    int all_len(int n){
        if(n >= 10000) return 9+2*90+3*900+4*9000+5*(n-9999);
        else if(n >= 1000) return 9+2*90+3*900+4*(n-999);
        else if(n >= 100) return 9+2*90+3*(n-99);
        else if(n >= 10) return 9+2*(n-9);
        else return n;
    }
public:
    vector<string> splitMessage(string m, int limit) {
        if(limit <= 5) return {};
        int n = m.size();
        for(int i = 1; i <= n; i++){
            int space = limit*i-3*i-digit(i)*i-all_len(i);
            int last = limit-3-digit(i)*2;
            int remain = n-(space-last);
            if(remain<0 || remain>last) continue;
            int idx = 0;
            vector<string> res(i);
            for(int j = 1; j < i; j++){
                int k = limit-3-digit(i)-digit(j);
                res[j-1] = m.substr(idx, k)+"<"+to_string(j)+"/"+to_string(i)+">";
                idx += k;
            }
            res[i-1] = m.substr(idx)+"<"+to_string(i)+"/"+to_string(i)+">";
            return res;
        }
        return {};
    }
};
