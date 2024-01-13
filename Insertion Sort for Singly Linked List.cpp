//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};

/* Function to print linked list */
void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}




// } Driver Code Ends
//User function Template for C++

/*Link list node
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};*/

class Solution
{
    public:
    Node* insnode(struct Node* head_ref, struct Node* act ){
        Node* prev=NULL;
        while(head_ref!=NULL){
            if(head_ref->data>act->data){
                break;
            }
            prev=head_ref;
            head_ref=head_ref->next;
        }
        if(prev==NULL){
            Node*temp=head_ref;
            act->next=temp;
            head_ref=act;
            return head_ref;
        }
        prev->next=act;
        act->next=head_ref;
        return NULL;
    }
    Node* insertionSort(struct Node* head_ref){
        //code here
        Node* currnode=head_ref;
        int flag=0;
        while(currnode->next!=NULL){
            Node* nextnode=currnode->next;
            if(currnode->data<=nextnode->data){
                currnode=nextnode;
                continue;
            }
            else{
                currnode->next=nextnode->next;
                Node*act=insnode(head_ref,nextnode);
                if(act!=NULL)head_ref=act;
            }
            
        }
        return head_ref;
        
    }
    
};

//{ Driver Code Starts.
int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int n;
		cin >> n;

		Node *head = NULL;
		Node *temp = head;

		for (int i = 0; i < n; i++) {
			int data;
			cin >> data;
			if (head == NULL)
				head = temp = new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}

        Solution ob;

		head = ob.insertionSort(head);
		printList(head);

		cout << "\n";



	}
	return 0;
}
// } Driver Code Ends
