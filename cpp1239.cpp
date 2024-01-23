// worked partially
class Solution {
public:
    int maxLength(vector<string>& arr) {
        int maxi=0, maxi2=arr[0].length();
        for(auto it:arr){
            if(it.length()>=maxi){
                maxi2 = maxi;
                maxi = it.length();
            }
        }
        return maxi+maxi2;
    }
};


// worked
class Solution {
public:
bool no_dupli(string &temp1, string &temp2){
        int arr[26] = {0};
        for(char &ch : temp1){
            if(arr[ch - 'a'] > 0) return true; 
            arr[ch - 'a']++; 
        }
        for(char &ch : temp2)if(arr[ch - 'a'] > 0) return true;
        return false; 
    }
    unordered_map<string, int> mp;

    int helper(int i, vector<string> &arr, string temp, int n){
        if(i >= n) return temp.length();
        int take = 0, no_take = 0;
        if(mp.find(temp) != mp.end()) return mp[temp];
        if(no_dupli(arr[i], temp))no_take = helper(i + 1, arr, temp, n); 
        else{
            no_take = helper(i + 1, arr, temp, n);
            take = helper(i + 1, arr, temp + arr[i], n); 
        }
        return mp[temp] = max(take, no_take);
    }
    int maxLength(vector<string>& arr) {
        mp.clear();
        return helper(0, arr, "", arr.size());
    }
};
