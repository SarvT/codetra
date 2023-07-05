class Solution {
public:
void merge( vector<pair<int,int>>&a,vector<int>&ans,int low,int high,int mid)
    {
        int dp=0;
        int i=low,j=mid+1;
        vector<pair<int,int>>temp;
        while(i<=mid&&j<=high)
        {
            if(a[i].first<=a[j].first)
            {
                temp.push_back({a[i].first,a[i].second});
                ans[a[i].second]+=dp;
                i++;
            }
            else
            {   
                  temp.push_back({a[j].first,a[j].second});
                  j++;
                  dp++;
                  
            } 
        }
        while(i<=mid)
        {
            temp.push_back({a[i].first,a[i].second});
            ans[a[i].second]+=dp;
                 i++;
        }
        while(j<=high)
        {
             temp.push_back({a[j].first,a[j].second});
             j++;
        }
        for(int i=low;i<=high;i++)
        {
            a[i]=temp[i-low];
        }
    }
    void divide( vector<pair<int,int>>&a,vector<int>&ans,int low,int high)
    {
        if(low==high) return;
       int mid=(low+high)/2;
        divide(a,ans,low,mid);
        divide(a,ans,mid+1,high);
        merge(a,ans,low,high,mid);
    }
    vector<int> countSmaller(vector<int>& nums) {
        int low=0,high=0;
         vector<pair<int,int>>a;
      for(auto i:nums)
      {
          a.push_back({i,high});
          high++;
      }
        vector<int>ans(high,0);
        divide(a,ans,0,high-1);
        
        return ans;
    }
};
