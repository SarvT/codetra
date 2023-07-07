// Leet
// Not worked
class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int cntT = 0, cntF = 0;
        for(char c: answerKey){
            if(c=='T') cntT++;
            else cntF++;
        }
        char r = 'T';
        if(cntT<cntF) r = 'F'; 
        int maxi = 0, cnt = 0, prev=0, n=answerKey.size();
        while(i<n){
            if(answerKey[i]==r && k!=0){
                cnt++;
                
            } else if(answerKey[i]!=r && k!=0){
                k--;
                prev=1;
            }
        }
    }
};



// worked
