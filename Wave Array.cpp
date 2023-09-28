class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to sort the array into a wave-like array.
    void convertToWave(int n, vector<int>& arr){
        
        // Your code here
         int i = 0,j=1;
        while(j<n){
            swap(arr[i],arr[j]);
            i = i+2;
            j = j+2;
        }
    }
};
