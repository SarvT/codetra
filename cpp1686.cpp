class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues){
        int n = aliceValues.size();
        vector<vector<int>> vec;
        for(int i=0;i<n;i++)vec.push_back({aliceValues[i]+bobValues[i],aliceValues[i],bobValues[i]});
        sort(vec.begin(),vec.end(),greater<vector<int>>());
        int aliceScore=0,bobScore=0;
        for(int i=0;i<n;i++){
            if(i%2==0) aliceScore += vec[i][1];
            else bobScore += vec[i][2];
        }
        if(aliceScore>bobScore) return 1;
        else if(bobScore>aliceScore) return -1;
        else return 0;
    }
};
