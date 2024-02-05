//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
/* structure for a Node */
struct Node
{
  int data;
  struct Node *next;
  
  Node(int x){
      data = x;
      next = NULL;
  }
  
};


// } Driver Code Ends
/* structure for a node */
/*
struct Node
{
  int data;
  struct Node *next;
  
  Node(int tmp2){
      data = tmp2;
      next = NULL;
  }
  
};
 */
 
// This function should return head of
// the modified list
class Solution
{
    public:
    Node *sortedInsert(Node* head, int data)
    {
       //Your code here
       if(head == NULL){
           struct Node* curr = new Node(data);
           curr->next = curr;
           return curr;
       }
       if(head->next == head){
           struct Node* curr = new Node(data);
           head->next = curr;
           curr->next = head;
           if(head->data <= data)return head;
           return curr;
       }
       bool flag = false;
       struct Node* tmp1 = new Node(data);
       if(head->data > data){
           tmp1->next = head;
           flag = true;
       }
       struct Node* tmp2 = head;
       while(true){
           if(tmp2->data <= data && data <= tmp2->next->data){
               struct Node* curr = new Node(data);
               curr->next = tmp2->next;
               tmp2->next = curr;
               return head;
           }
           if(tmp2->next == head){
               if(flag){
                   tmp2->next = tmp1;
                   return tmp1;
               }
               struct Node* curr = new Node(data);
               curr->next = head;
               tmp2->next = curr;
               return head;
           }
           tmp2 = tmp2->next;
       }
       return tmp1;
      return head;
    }
};

//{ Driver Code Starts.

/* Function to print Nodes in a given linked list */
void printList(struct Node *start)
{
  struct Node *temp;

  if(start != NULL)
  {
    temp = start;
    do { printf("%d ", temp->data);
      temp = temp->next;
    } while(temp != start);
    printf("\n");
  }
}
/* Driver program to test above functions */
int main()
{
int t,n,x;
scanf("%d",&t);
int arr;
  while(t--){
  scanf("%d",&n);
  int list_size, i;
  
  /* start with empty linked list */
  struct Node *start = NULL;
  struct Node *temp,*r;
  
  
    /* Create linked list from the array arr[].
    Created linked list will be 1->2->11->56->12 */
    if(n>0){
      scanf("%d",&arr);
    
    temp = new Node(arr);
    start=temp;
    r=start;
    }
    for (i = 0; i<n-1; i++)
    {
        scanf("%d",&arr);
        temp = new Node(arr);
        r->next=temp;
        r=r->next;
    }
    
    if(n>0)
    temp->next=start;
 
    scanf("%d",&x);
    Solution ob;
    start = ob.sortedInsert(start,x);
    printList(start);
    r=start;
    while(r!=start->next)
    {

      temp=start;
      start=start->next;
      free(temp);
    }
    free(start);
}
  return 0;
}

// } Driver Code Ends
