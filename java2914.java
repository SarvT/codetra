// wrote a different solution all working but for different ps
class Solution {
    public int minChanges(String s) {
        int cntZ=0, cntO=0;
        
        for(char c:s.toCharArray()){
            if(c=='0') cntZ++;
            else if(c=='1') cntO++;
        }
        if(s.length()==cntZ || s.length()==cntO) return 0;
        else return Math.min(cntZ, cntO);
        // return 0;
        
    }
}

//not worked
class Solution {
    public int minChanges(String s) {
        int cntZ=0, cntO=0;
        
        for(char c:s.toCharArray()){
            if(c=='0') cntZ++;
            else if(c=='1') cntO++;
        }
        if(s.length()==cntZ || s.length()==cntO) return 0;
        else return (Math.min(cntZ, cntO)%2);
        // return 0;

    }
}


// worked
class Solution {
    public int minChanges(String s) {
        int mini=0;
        for (int i = 0; i < s.length(); i += 2) {
            if (s.charAt(i) != s.charAt(i + 1)) mini++;
        }

        return mini;

    }
}
