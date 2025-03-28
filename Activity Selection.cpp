//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int activitySelection(vector<int> &start, vector<int> &finish) {
        // code here
        int n = start.size(), activities = 1, currEnd;
        vector<pair<int, int>> arr(n);
        
        
        for(int i=0;i<n;i++){
            arr[i].first = start[i];
            arr[i].second = finish[i];
        }
        
        sort(arr.begin(), arr.end(), [](pair<int,int> a, pair<int,int> b){
            if(a.second == b.second) return a.first < b.first;
            return a.second < b.second;
        });
        
        currEnd = arr[0].second;
        for(int i=1;i<n;i++){
            if(arr[i].first > currEnd){
                activities++;
                currEnd = arr[i].second;
            }
        }
        
        return activities;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        vector<int> start;
        int num;
        while (ss >> num)
            start.push_back(num);
        getline(cin, input);
        ss.clear();
        vector<int> finish;
        ss.str(input);
        while (ss >> num)
            finish.push_back(num);

        Solution obj;
        cout << obj.activitySelection(start, finish) << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends
