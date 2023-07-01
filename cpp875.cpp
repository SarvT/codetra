class Solution {
public:
    int eats(vector<int>& piles, int k){
        int sum=0;
        for(int pile:piles) sum+=(pile+(k-1))/k;
        return sum;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long left = h-1;
        left=accumulate(piles.begin(), piles.end(), left)/h;
        int right=*max_element(piles.begin(), piles.end());

        while(left<right){
            int mid = (left+right)/2;

            if(eats(piles, mid)<=h) right=mid;
            else left=mid+1;
        }
        return right;
    }
};
