
class Solution{
public:
    string findLargest(int N, int S){
        // code here
        string s;
        if((S==0 and N>1) or S>9*N) return "-1";
        
        for(int i=0; i<N; i++){
            if(S<=9){
                s.push_back(48+S);
                S=0;
            } else if(S>9){
                s.push_back(48+9);
                S-=9;
            }
        }
        return s;
        
    }
};
