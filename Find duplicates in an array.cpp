class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        // code here
        vector<int> result;
        for(int i=0;i<n;i++) arr[arr[i]%n] += n;
        for(int i=0;i<n;i++){
            if(arr[i] >= 2*n) result.emplace_back(i);
        }
        if(!result.empty()) return result;
        return {-1};
    }
};
