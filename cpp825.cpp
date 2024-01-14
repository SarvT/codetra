class Solution {
public:
int binarySearch(vector<int>&ages,int target)
{
    int l=0;
    int h=ages.size()-1;
    while(l<=h)
    {
        int mid=l+(h-l)/2;
        if (ages[mid]<=target)l=mid+1;
        else h=mid-1;
    }
    return l;
}
    int numFriendRequests(vector<int>& ages) {
        sort(ages.begin(),ages.end());
        int ans=0;
        for (int i=0;i<ages.size();i++)
        {
            int l=binarySearch(ages,ages[i]*0.5+7);
            int h=binarySearch(ages,ages[i]);
            ans+=max(h-l-1,0);
        }
        return ans;
    }
};
