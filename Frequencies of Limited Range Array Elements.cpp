class Solution{
    public:
    //Function to count the frequency of all elements from 1 to N in the array.
    void frequencyCount(vector<int>& arr,int N, int P)
    { 
        // code here
        map<int,int> hashmap;
        for(int i = 0; i < N ; i++){
            hashmap[arr[i]]++;
        }
        for(int i = 0; i < N ; i++){
            arr.at(i)=0;
        }
        for(auto iter : hashmap){
            if(iter.first <= N)
            arr[iter.first-1] = iter.second;
        }
    }
};
