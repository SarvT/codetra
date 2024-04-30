//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* num1, struct Node* num2)
    {
        // code here
        int c = 0;
        Node *p = num1, *q = num2;
        
        vector<int> a, b;
        
        while (p != NULL) {
            a.push_back(p->data);
            p = p->next;
        }
        
        while (q != NULL) {
            b.push_back(q->data);
            q = q->next;
        }
        
        int i = a.size() - 1, j = b.size() - 1;
        int k = max(i, j);          
        
        stack<int> s;
        
        while (k >= 0) 
        {                                       
            int sod = c;           
            if (i >= 0) sod += a[i--];
            if (j >= 0) sod += b[j--];
            
            c = sod / 10;
            s.push(sod % 10);
            k--;
        }
        
        if (c > 0)s.push(c);
        
        struct Node *nhead = new Node(0);
        Node *ptr = nhead;
        
        while (!s.empty() && s.top() == 0) s.pop();
        
        if (s.empty())return nhead; 
        
        
        while (!s.empty()){
            struct Node *newnode = new Node(s.top());
            s.pop();
            ptr->next = newnode;
            ptr = ptr->next;
        }
        
        return nhead->next; 
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* num1 = buildList(n);
        
        cin>>m;
        Node* num2 = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(num1,num2);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends
