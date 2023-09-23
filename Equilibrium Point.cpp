// worked --> failed for large input textcase 1011
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
    
        // Your code here
        if(n==1) return a[0];
        int i=0, j=n-1, sum1=a[i++], sum2=a[j--];
        while(i<j){
            if(sum1==sum2){
                sum1+=a[i++];
                sum2+=a[j--];
            }
            if(sum1<sum2)sum1+=a[i++];
            if(sum1>sum2)sum2+=a[j--];
            
            
        }
        // cout<<sum1<<" "<<sum2;
        if(i!=j || sum1!= sum2) return -1;
        return i+1;
    }

};


// worked
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
    
        // Your code here
        if(n==1) return a[0];
        //  if(n==1)return 1;
        
        for(int i=1;i<n;i++)a[i]+=a[i-1];
        
        for(int i=1;i<n-1;i++){
            if(a[i-1]==(a[n-1]-a[i]))return i+1;
        }
        
        return -1;
    }

};
