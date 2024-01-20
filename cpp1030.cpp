class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        vector<vector<int>>sol;
		map<int,vector<vector<int>>>mp;
		for(int i=0;i<rows;i++){
			for(int it=0;it<cols;it++){
				int dis=abs(i-rCenter)+abs(it-cCenter);
				mp[dis].push_back({i,it});
			}
		}
		for(auto i:mp)for(auto it:i.second) sol.push_back(it);
		return sol;
    }
};
