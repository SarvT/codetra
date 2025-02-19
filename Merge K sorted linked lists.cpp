//{ Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print nodes in a given linked list */
void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    cout << endl;
}


// } Driver Code Ends
/*Linked list Node structure

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
  void add(Node* root,vector<int> &vec){
        if(!root)return;
        vec.push_back(root->data);
        add(root->next,vec);
        return;
        
    }
    Node* helper(int i,int n,vector<int> &arr){
        if(i==n)return NULL;
        Node* temp = new Node(arr[i]);
        temp->next = helper(i+1,n,arr);
        return temp;    
    }
    Node* mergeKLists(vector<Node*>& arr) {
        // Your code here
        vector<int> vec;
        int n=arr.size();
        for(int i=0;i<n;i++)add(arr[i],vec);
        
        sort(vec.begin(),vec.end());
        
        int new_node=vec.size();
        return helper(0,new_node,vec);
    }
};


//{ Driver Code Starts.

// Driver program to test the above functions
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        cin >> n;
        cin.ignore();

        vector<Node*> v(n);

        for (int i = 0; i < n; i++) {
            string line;
            getline(cin, line);
            stringstream ss(line);

            Node* head = new Node(0);
            Node* temp = head;
            int x;
            while (ss >> x) {
                Node* newNode = new Node(x);
                temp->next = newNode;
                temp = temp->next;
            }
            v[i] = head->next;
        }

        Solution ob;
        Node* head = ob.mergeKLists(v);
        printList(head);
    }

    return 0;
}

// } Driver Code Ends
