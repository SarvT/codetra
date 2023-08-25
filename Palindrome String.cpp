// worked haha
class Solution{
public:	
	
	
	int isPalindrome(string S)
	{
	    // Your code goes here
	    int i=0, n=S.size()-1;
	    while(i<n){
	        if(S[i++]!=S[n--]) return 0;
	    }
	    return 1;
	}

};
