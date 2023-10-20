
class Solution {
  public:
    int isPossible(int N, int arr[]) {
        // code here
        int sum=0;
        for(int i=0; i<N; i++){
            
        int it = arr[i];
        while(it > 0) {
                sum += it % 10;
                it /= 10;
            }
        }
        // sum+=arr[i];
        if(sum%3==0) return 1;
        return 0;
    }
};
