// Leet

class Solution {
public:
    int largestVariance(string s) {
        int lmax=0, gmax=0, n=s.size();
        vector<int> cnt(26, 0);
        for(char c: s) cnt[c-'a']++;
        for(int i=0; i<26; i++){
            for(int j=0; j<26; j++){
                if(i==j || cnt[i] ==0 || cnt[j]==0) continue;
                char major = 'a'+i;
                char minor = 'a'+j;
                int mjCnt = 0;
                int mrCnt = 0;

                int rem = cnt[j];

                for(char c: s){
                    if(c==major){
                        mjCnt++;
                    }
                    if(c == minor){
                        mrCnt++;
                        rem--;
                    }

                    if(mrCnt>0)gmax = max(gmax, mjCnt-mrCnt);

                    if(mjCnt<mrCnt && rem>0){
                        mjCnt=0;
                        mrCnt=0;
                    }
                }
            }
        }
        return gmax;
    }
};
