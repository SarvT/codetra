gfg
not worked
int missingNumber(int arr[], int n) 
    { 
        // Your code here
        int i=1, idx=0;
        sort(arr, arr+n);
        while(idx<n){
            if(arr[idx]<=0){
                idx++;
            } else if(arr[idx]>0 && arr[idx]==i){
                i++;
                idx++;
            } else if(arr[idx]>0 && arr[idx]!=i){
                return i;
            }
        }
        return i;
    } 


// worked
class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) 
    { 
        // Your code here
        int i=1;
        sort(arr, arr+n);
        for(int idx=0; idx<n; idx++){
            if(arr[idx]==i) i++;
            
        }
        return i;
    } 
};

