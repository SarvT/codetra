// not worked
class Solution
{
    public:
    vector<int> find(int arr[], int n , int x )
    {
        // code here
        vector<int> ans(2, -1);
        int i=0, k=n-1;
        while(i<=k){
            int mid=(i+k)/2;
            if(arr[mid]==x){
                i=mid;
                k=mid;
                while(arr[mid]==x){
                    if(arr[i-1]==x) i--;
                    else if(arr[k+1]==x) k++;
                    else {
                        ans.emplace_back(i);
                        ans.emplace_back(k);
                        break;
                    }
                }
                
                break;
            }
            if(arr[mid]<x) i=mid+1;
            if(arr[mid]>x) k=mid;
        }
        return ans;
        
    }
};



need to check once 
 // code here
        vector<int> ans(2, -1);
        int i=0, k=n-1;
        // if(i==k)
        while(i<=k){
            if(ans[0]==-1 && arr[i]==x) ans[0]=i;
            if(ans[1]==-1 && arr[k]==x) ans[1]=k;
            i++;
            k--;
            
        }
        // if(ans[0]!=-1 && ans[1]==-1) ans[1]=ans[0];
        // if(ans[0]==-1 && ans[1]!=-1) ans[0]=ans[1];
        return ans;



// worked
vector <int> ans;
        int left,right;
        bool isFoundLeft=false,isFoundRight=false;
        // for left element
        for(int i=0;i<n;i++){
            if( arr[i] == x){
                ans.push_back(i);
                isFoundLeft=true;
                break;
            }
        }
        
        // for right element
        for(int i=n;i>=0;i--){
            if(arr[i] == x){
                ans.push_back(i);
                isFoundRight=true;
                break;
            }
        }
        
        if(!isFoundLeft || !isFoundRight)
        {
            ans.push_back(-1);
            ans.push_back(-1);
    
        }
        
        
        return ans;
