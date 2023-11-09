worked
class Solution{
    public:
    /*Function to count zeros in each column
    * N : Number of rows and columns in array
    M is the matrix that is globally declared
    */
    int columnWithMaxZeros(vector<vector<int>>arr,int N){
        
        // Your code here
        int col=0, cnt=0, prv=0;
        for(int j=0; j<N; j++){
            cnt=0;
            // prv=0;
            for(int i=0; i<N; i++){
                if(arr[i][j]==0) cnt++;
            }
            // col=max(cnt,col);
            if(cnt>prv){
                prv=cnt;
                col=j;
            }
        }
        return col;
        
    }
};




// same
class Solution{
    public:
    /*Function to count zeros in each column
    * N : Number of rows and columns in array
    M is the matrix that is globally declared
    */
    int columnWithMaxZeros(vector<vector<int>>arr,int N){
        
        // Your code here
        int min=N, s=0, col=-1;
        for (int i=0; i<N; i++){
            for (int j=0; j<N; j++) s+=arr[j][i];
            if (s<min){
                col=i;
                min=s;
            }
            s=0;
        }
        return col;
        
    }
};
