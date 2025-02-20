// charm solution
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string str = nums[0];
        for(int i=0; i<str.size(); i++) str[i]='0';

        for(int i=0; i<str.size(); i++){
            string newstr = str;
            newstr[i]='1';
            if(find(nums.begin(), nums.end(), newstr) == nums.end()){
                return newstr;
            }
        }
        return str;
    }
};
