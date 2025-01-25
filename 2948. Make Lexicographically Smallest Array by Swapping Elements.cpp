//partial
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n=nums.size();
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                if((abs(nums[i]-nums[j]))<=limit){
                    if(nums[i]>nums[j]){
                        int tmp = nums[j];
                        nums[j]=nums[i];
                        nums[i]=tmp;
                    }
                }
            }
        }
        return nums;
    }
};

///false approach
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n=nums.size();
        for(int i=n-1; i>0; i--){
            for(int j=i-1; j>=0; j--){
                if((abs(nums[i]-nums[j]))<=limit){
                    if(nums[i]>nums[j]){
                        int tmp = nums[j];
                        nums[j]=nums[i];
                        nums[i]=tmp;
                    }
                }
            }
        }
        return nums;
    }
};

//partial
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n=nums.size();
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                if((abs(nums[i]-nums[j]))<=limit){
                    if(nums[i]>nums[j]){
                        int tmp = nums[j];
                        nums[j]=nums[i];
                        nums[i]=tmp;
                        if((i-1)>=0)i--;
                        // i=0;
                    }
                }
            }
        }
        return nums;
    }
};

//partial
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n=nums.size();
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                if((abs(nums[i]-nums[j]))<=limit){
                    if(nums[i]>nums[j]){
                        int tmp = nums[j];
                        nums[j]=nums[i];
                        nums[i]=tmp;
                        if((i-1)>=0)i--;
                        // i=0;
                    }
                }
            }
        }
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                if((abs(nums[i]-nums[j]))<=limit){
                    if(nums[i]>nums[j]){
                        int tmp = nums[j];
                        nums[j]=nums[i];
                        nums[i]=tmp;
                        // if((i-1)>=0)i--;
                        // i=0;
                    }
                }
            }
        }

        return nums;
    }
};

//submitted

class Node {
public:
    int value;
    int index;
    Node(int val, int idx) {
        value = val;
        index = idx;
    }
};
class cmp {
public:
    bool operator()(Node* a, Node* b) { return a->value < b->value; }
};



    class Solution {
    void helper(auto& pq, int& start, vector<int>& nums, vector<Node*>& temp) {
        while (!pq.empty()) {
            nums[pq.top()] = temp[start]->value;
            start++;
            pq.pop();
        }
    }
    public:
        vector<int> lexicographicallySmallestArray(vector<int>& nums,
                                                   int limit) {
            // int n=nums.size();
            // for(int i=0; i<n-1; i++){
            //     for(int j=i+1; j<n; j++){
            //         if((abs(nums[i]-nums[j]))<=limit){
            //             if(nums[i]>nums[j]){
            //                 int tmp = nums[j];
            //                 nums[j]=nums[i];
            //                 nums[i]=tmp;
            //                 if((i-1)>=0)i--;
            //                 // i=0;
            //             }
            //         }
            //     }
            // }
            // for(int i=0; i<n-1; i++){
            //     for(int j=i+1; j<n; j++){
            //         if((abs(nums[i]-nums[j]))<=limit){
            //             if(nums[i]>nums[j]){
            //                 int tmp = nums[j];
            //                 nums[j]=nums[i];
            //                 nums[i]=tmp;
            //                 // if((i-1)>=0)i--;
            //                 // i=0;
            //             }
            //         }
            //     }
            // }

            int start = 0;
            vector<Node*> temp;
            priority_queue<int, vector<int>, greater<int>> pq;
            for (int i = 0; i < nums.size(); i++) {
                temp.push_back(new Node(nums[i], i));
            }
            sort(temp.begin(), temp.end(), cmp());
            for (int i = 0; i < temp.size(); i++) {
                if (start != i && temp[i]->value - temp[i - 1]->value > limit) {
                    helper(pq, start, nums, temp);
                }
                pq.push(temp[i]->index);
            }
            helper(pq, start, nums, temp);

            return nums;
        }
    };
