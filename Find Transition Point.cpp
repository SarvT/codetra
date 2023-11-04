class Solution
{
public:    
    
    int transitionPoint(int arr[], int n) {
        // code here
        int l=0, h=n-1;
        int mid=(l+h)/2;
        while(l<h){

            if(l==1) return l;
            else if(mid==1) h=mid;
            else if(mid==0) l=mid+1;
            
        }
        return -1;
    }
};



class Solution
{
public:    
    
    int transitionPoint(int arr[], int n) {
        // code here
        if(n==0) return -1;
        int l=0, h=n-1, ans=-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(arr[mid]==0) l=mid+1;
            else if(arr[mid]==1){
                 ans=mid;
                 h=mid-1;
            }
            
        }
        return ans;
    }
};
