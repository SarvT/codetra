class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<double , pair<int,int>> > pq;
        for(int i = 0 ; i < arr.size() ; i++){
            for(int j = i+1 ; j < arr.size() ; j++){
                double val = ((double)arr[i]/(double)arr[j]);
                pq.push({val , {arr[i] , arr[j]}});

                if(pq.size() > k)pq.pop();
            }
        }

        auto top = pq.top();

        int first_val = top.second.first;
        int second_val = top.second.second;

        return {first_val , second_val};
    }
};
