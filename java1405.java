// not worked --> TLE

class Solution {
    String sol = "";
    // boolean checkIfHappy(int a, int b, int c){
    //     for(int i=0; i<str.length(); i++){
    //         if()
    //     }
    // }

    void addChar(char c, int val){
        if(val<0) return;
        for(int i=1; i<=val; i++) sol+=c;
        System.out.print(c);
    }
    public String longestDiverseString(int a, int b, int c) {
        String str = "";

        // for(int i=1; i<=a; i++) str+='a';
        // for(int i=1; i<=a; i++) str+='b';
        // for(int i=1; i<=a; i++) str+='c';
        
        // for(int i=1; i<=a; i++) str+='a';
        // for(int i=1; i<=b; i++) str+='b';
        // for(int i=1; i<=c; i++) str+='c';
        char prev = 'n';
        while(a>0 || b>0 || c>0){
            if((a>=b && a>=c) && (prev!='a') && (a>0)){
                if(a>0){
                    if(a>=2){
                        addChar('a', 2);
                        a-=2;
                        prev='a';
                    } 
                    else{
                        addChar('a', a);
                        a=0;
                        prev='a';
                    } 
                }
            // maxi = 'a'
            } 
            else if((b>=a && b>=c) && (prev!='b')&& (b>0)){
                if(b>0){
                    if(b>=2){
                        addChar('b', 2);
                        b-=2;
                        prev='b';
                    } 
                    else{
                        addChar('b', b);
                        b=0;
                        prev='b';
                    } 
                }
            // maxi = 'b'

            } 
            else if((c>=b && c>=a) && (prev!='c')&& (c>0)){
                if(c>0){
                    if(c>=2){
                        addChar('c', 2);
                        c-=2;
                        prev='c';
                    } 
                    else{
                        addChar('c', c);
                        c=0;
                        prev='c';
                    } 
                }
            // maxi = 'c'
            } 
        }
        return sol;
    }
}




// worked
class Solution {
    
    public String longestDiverseString(int a, int b, int c) {
        int cnta = 0, cntb = 0, cntc = 0;
        int totalCnt = a + b + c;
        StringBuilder ans = new StringBuilder();

        for (int i = 0; i < totalCnt; i++) {
            if ((a >= b && a >= c && cnta != 2) ||(a > 0 && (cntb == 2 || cntc == 2))) {
                ans.append('a');
                a--;
                cnta++;
                cntb = 0;
                cntc = 0;
            } else if ((b >= a && b >= c && cntb != 2) ||(b > 0 && (cntc == 2 || cnta == 2))) {
                ans.append('b');
                b--;
                cntb++;
                cnta = 0;
                cntc = 0;
            } else if ((c >= a && c >= b && cntc != 2) ||(c > 0 && (cnta == 2 || cntb == 2))) {
                ans.append('c');
                c--;
                cntc++;
                cnta = 0;
                cntb = 0;
            }
        }
        return ans.toString();
    }
}
