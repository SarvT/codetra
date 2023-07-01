class Solution {
public:
void rec(int i,int tar,vector<int>&can,vector<vector<int>>&res,vector<int>&temp,int k){
     if(tar==0){
         if(temp.size()==k)
                res.push_back(temp);
                return;
            } 
        for(int j=i;j<can.size();j++){
            if(j>i && (can[j]==can[j-1])) continue;
            if(can[j]>tar) break;
            temp.push_back(can[j]);
            rec(j+1,tar-can[j],can,res,temp,k);
            temp.pop_back();
        }
}
    vector<vector<int>> combinationSum3(int k, int tar) {
        vector<int>can;
        for(int i=0;i<9;i++){
            can.push_back(i+1);
        }
        vector<vector<int>>res;
        vector<int>temp;
        rec(0,tar,can,res,temp,k);
        return res;
    }
};
