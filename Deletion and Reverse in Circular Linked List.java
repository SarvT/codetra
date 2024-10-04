// not working

//{ Driver Code Starts
import java.io.*;
import java.util.*;

class Node {
    int data;
    Node next;

    Node(int x) {
        data = x;
        next = null;
    }
}

class LinkedList {
    // Function to print nodes in a given circular linked list
    static void printList(Node head) {
        if (head == null) {
            System.out.println("empty");
            return;
        }
        Node temp = head;
        do {
            System.out.print(temp.data + " ");
            temp = temp.next;
        } while (temp != head);
        System.out.println();
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());

        while (t-- > 0) {
            List<Integer> arr = new ArrayList<>();
            String input = br.readLine();
            StringTokenizer st = new StringTokenizer(input);
            while (st.hasMoreTokens()) {
                arr.add(Integer.parseInt(st.nextToken()));
            }
            int key = Integer.parseInt(br.readLine());
            Node head = new Node(arr.get(0));
            Node tail = head;
            for (int i = 1; i < arr.size(); ++i) {
                tail.next = new Node(arr.get(i));
                tail = tail.next;
            }
            tail.next = head; // Make the list circular
            Solution ob = new Solution();
            Node current = ob.deleteNode(head, key);
            Node rev = ob.reverse(current);
            printList(rev);
        }
    }
}

// } Driver Code Ends


/*class Node
{
    int data;
    Node next;
    Node(int d)
    {
        data=d;next=null;
    }
}*/

class Solution {
    // Function to reverse a circular linked list
    Node reverse(Node head) {
        // code here
        // Stack<Node> st = new Stack<>();
        if(head==null)return head;
        // int initVal = head.data;
        Node initNode = head;
        Node nxt=null, prv=null, end=head;
        do{
            end=end.next;
        }while(end.next!=head);
        do{
            nxt = initNode.next;
            initNode.next=prv;
            prv=initNode;
            initNode=nxt;
            // st.push(head);
            // head=head.next;
            // System.out.println(head.data);
        }while(initNode!=head);
        head.next=prv;
        head=prv;
        end.next=head;
        // Node newHead = st.peek();
        // Node tmp = st.pop();
        // st.pop();
        
        // while(st.empty()==false){
        //     // st.add(head);
        //     tmp.next=st.pop();
        //     // st.pop();
        // }
        // tmp.next=newHead;
        return head;
        
    }

    // Function to delete a node from the circular linked list
    Node deleteNode(Node head, int key) {
        // code here
        if(head==null)return null;
        Node prev = null;
        Node curr = head;
        if(head.data==key){
            Node end=head;
            while(end.next!=head)end=end.next;
            // head=head.next;
        
        if(head==head.next)return null;
        end.next=head.next;
        return head.next;
        }
        // prev.next=head.next;
        // return head;
        do{
            prev=curr;
            curr=curr.next;
        }while(curr!=head && curr.data!=key);
        
        if(curr.data==key) prev.next=curr.next;
        return head;
    }
}




//{ Driver Code Starts
import java.io.*;
import java.util.*;

class Node {
    int data;
    Node next;

    Node(int x) {
        data = x;
        next = null;
    }
}

class LinkedList {
    // Function to print nodes in a given circular linked list
    static void printList(Node head) {
        if (head == null) {
            System.out.println("empty");
            return;
        }
        Node temp = head;
        do {
            System.out.print(temp.data + " ");
            temp = temp.next;
        } while (temp != head);
        System.out.println();
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());

        while (t-- > 0) {
            List<Integer> arr = new ArrayList<>();
            String input = br.readLine();
            StringTokenizer st = new StringTokenizer(input);
            while (st.hasMoreTokens()) {
                arr.add(Integer.parseInt(st.nextToken()));
            }
            int key = Integer.parseInt(br.readLine());
            Node head = new Node(arr.get(0));
            Node tail = head;
            for (int i = 1; i < arr.size(); ++i) {
                tail.next = new Node(arr.get(i));
                tail = tail.next;
            }
            tail.next = head; // Make the list circular
            Solution ob = new Solution();
            Node current = ob.deleteNode(head, key);
            Node rev = ob.reverse(current);
            printList(rev);
        }
    }
}

// } Driver Code Ends




// worked
/*class Node
{
    int data;
    Node next;
    Node(int d)
    {
        data=d;next=null;
    }
}*/

class Solution {
    // Function to reverse a circular linked list
    Node reverse(Node head) {
        // code here
        if(head==null || head.next == head) return null;

        Node pre = head;
        Node current = head.next;
        Node next;
        // Node first = current;
        do{
            next = current.next;
            current.next = pre;
            pre = current;
            current = next;
        }while(head != current);
         head.next = pre; // Fix the circular link
         head = pre;
        return head;
        
    }

    // Function to delete a node from the circular linked list
    Node deleteNode(Node end, int key) {
        // code here
        if(end.data == key){
             Node temp = end;
            while (temp.next != end) {
                temp = temp.next;
            }
            temp.next = end.next;
           
            return end.next;
        }
        
        Node prv = end;
        Node curr = end.next;
       
        do {
            if (curr.data == key) {
                prv.next = curr.next; // Bypass the node with the key
                return end;  // Return the updated end node pointer
            }
            prv = curr;
            curr = curr.next;
        } while (curr != end.next); // Loop until we traverse the entire circular list

        // If no node with the key was found, return the unchanged list
        return end;
    }
}
