// TLE
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the next greater element for each element of the array.
    vector<int> nextLargerElement(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int> vec;
        for(int i=0; i<n-1; i++){
            bool flag = false;
            for(int j=i+1; j<n; j++){
                if(arr[i]<arr[j]) {
                    vec.emplace_back(arr[j]);
                    flag=true;
                    break;
                }// if(arr[i]>arr[j]) vec.emplace_back(arr[j]);
            }
            if(!flag) vec.emplace_back(-1);
        }
        vec.emplace_back(-1);
        return vec;
    }
};

//{ Driver Code Starts.

int main() {
    int t; // Number of test cases
    cin >> t;
    cin.ignore(); // Ignore the newline after reading t
    while (t--) {
        vector<int> a;
        string input;

        // Reading the entire input line for the array
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num); // Read the array elements from input string

        Solution obj;
        vector<int> result = obj.nextLargerElement(a);

        // Print the result in the required format
        for (int i = 0; i < result.size(); i++) {
            if (i != 0)
                cout << " ";
            cout << result[i];
        }
        cout << endl;        // Ensure new line after each test case output
        cout << "~" << endl; // Ensure new line after each test case output
    }

    return 0;
}

// } Driver Code Ends


// worked
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the next greater element for each element of the array.
    vector<int> nextLargerElement(vector<int>& arr) {
        // code here
        // int n=arr.size();
        // vector<int> vec;
        // for(int i=0; i<n-1; i++){
        //     bool flag = false;
        //     for(int j=i+1; j<n; j++){
        //         if(flag) break;
                
        //         if(arr[i]<arr[j]) {
        //             vec.emplace_back(arr[j]);
        //             flag=true;
        //             break;
        //         }// if(arr[i]>arr[j]) vec.emplace_back(arr[j]);
        //     }
        //     if(!flag) vec.emplace_back(-1);
        // }
        // vec.emplace_back(-1);
        // return vec;
        int n=arr.size();
        vector<int> res(n,-1);
        stack<int> st;
        st.push(arr[n-1]);
        for(int i=n-2;i>=0;i--)
        {
            while(st.empty()==false && st.top()<=arr[i])
                st.pop();
            
            if(st.empty()==false)
                res[i]=st.top();
            
            st.push(arr[i]);
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t; // Number of test cases
    cin >> t;
    cin.ignore(); // Ignore the newline after reading t
    while (t--) {
        vector<int> a;
        string input;

        // Reading the entire input line for the array
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num); // Read the array elements from input string

        Solution obj;
        vector<int> result = obj.nextLargerElement(a);

        // Print the result in the required format
        for (int i = 0; i < result.size(); i++) {
            if (i != 0)
                cout << " ";
            cout << result[i];
        }
        cout << endl;        // Ensure new line after each test case output
        cout << "~" << endl; // Ensure new line after each test case output
    }

    return 0;
}

// } Driver Code Ends
