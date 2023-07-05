// Leet
// Worked
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size()-1, end=arr[n]+k, start=1, i=0;
        while(start<=end){
            if(k==0) return start-1;
            if(i<=n && arr[i] != start){
                k--;
                start++;
            }
            else if(i<=n && arr[i] == start) {
                i++;
                start++;
            }
            else {
                start += k;
                k=0;

            }
        }
        return start-1;
    }
};
