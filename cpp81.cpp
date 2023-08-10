Leet
Not worked
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.size() == 1){
            if(nums[0]==target) return true;
        }
        sort(nums.begin(), nums.end());
        int l=0, r=nums.size()-1;
        while(l<r){
            int mid=l+(r-l)/2;
            if(nums[mid]==target) return true;
            else if(nums[mid]>=target) r=mid;
            else if(nums[mid]<=target) l=mid+1;
        }
        return false;
    }
};

Worked
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return false;
        int end = n - 1;
        int start = 0;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (nums[mid] == target) {
                return true;
            }

            if (!isBinarySearchHelpful(nums, start, nums[mid])) {
                start++;
                continue;
            }

            bool pivotArray = existsInFirst(nums, start, nums[mid]);

            bool targetArray = existsInFirst(nums, start, target);
            if (pivotArray ^ targetArray) { 
                if (pivotArray) {
                    start = mid + 1;
                    } else {
                    end = mid - 1;
                    }
            } else { 
                if (nums[mid] < target) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
        return false;
    }
    bool isBinarySearchHelpful(vector<int>& nums, int start, int element) {
        return nums[start] != element;
    }
    bool existsInFirst(vector<int>& nums, int start, int element) {
        return nums[start] <= element;
    }
};
