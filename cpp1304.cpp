class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> v(n);
        if(n&1){
            v[n-1]=0;
            for(int i=0; i<n-1; i+=2){
                v[i]=i+1;
                v[i+1]=-(i+1);

            } 
            }else{
                for(int i=0; i<n; i+=2){

                v[i]=i+1;
                v[i+1]=-(i+1);
                }
        } 
        return v;
    }
};
