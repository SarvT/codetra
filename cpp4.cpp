// Leet
// Not worked
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size()-1, m=nums2.size()-1;
        int i=0, j=0, med=(n+m)/2;
        vector<int> ans;
        while(i < n && j < m){
            if(nums1[i]<nums2[j]){
                i++;
                ans.emplace_back(nums1[i]);
            } else if(nums1[i]>nums2[j]){
                ans.emplace_back(nums2[j]);
                j++;
            }
        }
        double sol =0 ;
        if(med & 1) sol = ans[med];
        // else sol = (ans[med] + ans[med+1])/2; 
        return sol;
    }
};


// Worked
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(), n=nums2.size();
        if(n<m) return findMedianSortedArrays(nums2, nums1);
        int i=0, j=m;
        while(i<=j){
            int partA = (i+j)/2;
            int partB = (m+n+1)/2;

            int mlA = (!partA) ? INT_MIN:nums1[partA-1];
            int mrA = (partA == m) ? INT_MAX:nums1[partA];
            int mlB = (!partB) ? INT_MIN:nums2[partB-1];
            int mrB = (partB == n) ? INT_MAX:nums2[partB];

            if(mlA <= mrB && mlB <= mrA){
                if((m+n)%2==0) return (max(mlA, mlB)+min(mrA, mrB))/2.0;
                else return max(mlA, mlB);
            } else if(mlA>mlB) j = partA-1;
            else i = partA+1;
        }
        return 0.0;
    }
};


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int m = nums1.size(), n = nums2.size();
        int left = 0, right = m;
        
        while (left <= right) {
            int partitionA = (left + right) / 2;
            int partitionB = (m + n + 1) / 2 - partitionA;
            
            int maxLeftA = (partitionA == 0) ? INT_MIN : nums1[partitionA - 1];
            int minRightA = (partitionA == m) ? INT_MAX : nums1[partitionA];
            int maxLeftB = (partitionB == 0) ? INT_MIN : nums2[partitionB - 1];
            int minRightB = (partitionB == n) ? INT_MAX : nums2[partitionB];
            
            if (maxLeftA <= minRightB && maxLeftB <= minRightA) {
                if ((m + n) % 2 == 0) {
                    return (max(maxLeftA, maxLeftB) + min(minRightA, minRightB)) / 2.0;
                } else {
                    return max(maxLeftA, maxLeftB);
                }
            } else if (maxLeftA > minRightB) {
                right = partitionA - 1;
            } else {
                left = partitionA + 1;
            }
        }
        
        return 0.0;
    }
};
