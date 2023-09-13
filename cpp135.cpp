// not worked
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        int prev=1, cnt=0;
        if(ratings[0]>ratings[1]) prev++;
        for(int i=1; i<n-1; i++){
            if(ratings[i]==ratings[i-1]) prev=prev;
            else if((ratings[i]>ratings[i+1]) || (ratings[i]>ratings[i-1])) {
                // cnt+=prev+1;
                prev=prev+1;
            }
            else if((ratings[i]<ratings[i+1]) && (ratings[i]<ratings[i-1])) {
                prev=1;
                // cnt+=1;
            }
                cnt+=prev;
                // prev=1;
            cout<<cnt;
        }
        if(ratings[n-1]>ratings[n-2]) cnt+=prev+1;
        else if(ratings[n-1]<ratings[n-2]) cnt+=1;
        else cnt+=prev;
        return cnt;
    }
};


// worked
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int> candies(n, 1);

        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        for (int i = n - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = std::max(candies[i], candies[i + 1] + 1);
            }
        }

        int totalCandies = 0;
        for (int candy : candies) {
            totalCandies += candy;
        }

        return totalCandies;
    }
};
