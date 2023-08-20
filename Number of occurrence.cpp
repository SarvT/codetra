class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
		void solve(int arr[] ,int p , int n , int x , int &a ){
        if (p > n) {
            return; // Base case: array is empty or search range is invalid
        }
        int h = (p+n)/2 ;
        if(arr[h]==x){
            a++ ;
            solve(arr , h+1 , n , x ,a);
            solve(arr ,p , h-1 , x , a);
        }
        else if(arr[h]>x){
            solve(arr ,p , h-1 , x , a);
        } else if (arr[h]<x){
            solve( arr , h+1 , n , x ,a);
        }
    }
    
    
    
	int count(int arr[], int n, int x) {
	    // code here
	    int a = 0 ;
        solve(arr, 0 , n-1 , x , a);
        return a ;
	}
};
