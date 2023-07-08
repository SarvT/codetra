// gfg
// not worked --> got wrong assumption
bool findTriplets(int arr[], int n)
    { 
        if(n<=3) return false;
        //Your code here
        for(int i=0; i< n-2; i++){
            if((arr[i]+arr[i+1]+arr[i+2]) == 0) return true;
        }
        return false;
    }


Find triplets with zero sum
class Solution{
  public:
  
  bool rec(int arr[], int n, int l, int sum){
      if(l>=2) return false;
      if(l==2 && sum==0) return true;
      for(int i=l; i<n; i++){
          
      sum+=arr[i];
      rec(arr, n, i, sum);
      sum-=arr[i];
    //   rec(arr, n, l+1, sum);
      }
      
  }
    //Function to find triplets with zero sum.
    bool findTriplets(int arr[], int n)
    { 
        if(n<=3) return false;
        // //Your code here
        // for(int i=0; i< n-2; i++){
        //     if((arr[i]+arr[i+1]+arr[i+2]) == 0) return true;
        // }
        // return false;
        return rec(arr, n, 0, 0);
    }
};


// worked
 sort(arr, arr + n);
        for (int i = 0; i < n - 2; i++) {
            int left = i + 1; 
            int right = n - 1; 
            while (left < right) {
                int sum = arr[i] + arr[left] + arr[right];
                if (sum == 0)
                    return true; 
                if (sum < 0)
                    left++; 
                else
                    right--;
            }
        }
        return false; 
