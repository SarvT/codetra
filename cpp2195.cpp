// Leet
// Not worked
class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        long long res=0;
        sort(nums.begin(), nums.end());
        int n=nums.size(), start=1, end=nums[n-1]+k, i=0;
        while(start<=end){
            if(k==0) return res;
            if(i<n && start != nums[i]){
                k--;
                res+=start;
                start++;
                // start++;
            } else if(i<n && start == nums[i]){
                // res+=start;
                i++;
                start++;
            } else{
                k--;
                res+=start;
                start++;
            }
            // if(k==0) return res;
            cout<<k;
        }
        return res;
    }
};


// worked
class Solution
{
public:
    long long minimalKSum(vector<int> &nums, int k)
    {
        long long sum = 0, num = 0;
        int ind = 0;
        sort(nums.begin(), nums.end());

        while (k > 0 && ind < nums.size())
        {

            long long n = nums[ind] - num - 1;
            if (n >= 0)
            {
                long long a;
                if (k >= n)
                {
                    k = k - n;
                    a = nums[ind] - 1;
                }

                else if (k < n)  
                {
                    a = num + k;
                    k = 0;
                }

                if (a >= num) sum += ((a * (a + 1)) / 2) - ((num * (num + 1)) / 2);
            }

            num = nums[ind];
            ind++;
        }

        long long a = k + nums.back();
        long long last = nums.back();

        sum += ((a * (a + 1)) / 2) - ((last * (last + 1)) / 2);

        return sum;
    }
};
