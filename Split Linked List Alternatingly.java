worked --> partially
//{ Driver Code Starts
import java.util.*;

class Node {
    int data;
    Node next;

    Node(int x) {
        data = x;
        next = null;
    }
}

public class Main {
    public static void printList(Node node) {
        while (node != null) {
            System.out.print(node.data + " ");
            node = node.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        sc.nextLine();

        while (t-- > 0) {
            List<Integer> arr = new ArrayList<>();
            String input = sc.nextLine();
            Scanner ss = new Scanner(input);

            while (ss.hasNextInt()) {
                arr.add(ss.nextInt());
            }

            Node head = new Node(arr.get(0));
            Node tail = head;

            for (int i = 1; i < arr.size(); ++i) {
                tail.next = new Node(arr.get(i));
                tail = tail.next;
            }

            Solution ob = new Solution();
            Node[] result = ob.alternatingSplitList(head);
            printList(result[0]);
            printList(result[1]);
        }

        sc.close();
    }
}

// } Driver Code Ends


// User function Template for Java
/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
    // Function to append a new node with newData at the end of a linked list
    Node[] alternatingSplitList(Node head) {
        // code here
        if(head==null || head.next==null){
            Node[] headList = new Node[1];
            headList[0]=head;
            return headList;
        } 
        Node tmp = head.next, one = head, two = head.next;
        int cnt=0;
        while((one.next.next!=null && two.next.next!=null) && (one.next!=null && two.next!=null)) {
            cnt++;
            one.next = one.next.next;
            two.next = two.next.next;
            
            one = one.next;
            two = two.next;
        }
        if(cnt==2){
            one.next = one.next.next;
            two.next = null; 
        }
        if(cnt%2!=0){
            one.next = one.next.next;
            two.next = null; 
            // if(one.next != null)one.next = null;
        } else{
            // if(two.next != null)two.next = null;
            two.next = two.next.next;
            one.next = null; 
        }
        Node[] sol = new Node[2];
        sol[0] = head;
        sol[1] = tmp;
        return sol;
    }
}


// worked
//{ Driver Code Starts
import java.util.*;

class Node {
    int data;
    Node next;

    Node(int x) {
        data = x;
        next = null;
    }
}

public class Main {
    public static void printList(Node node) {
        while (node != null) {
            System.out.print(node.data + " ");
            node = node.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        sc.nextLine();

        while (t-- > 0) {
            List<Integer> arr = new ArrayList<>();
            String input = sc.nextLine();
            Scanner ss = new Scanner(input);

            while (ss.hasNextInt()) {
                arr.add(ss.nextInt());
            }

            Node head = new Node(arr.get(0));
            Node tail = head;

            for (int i = 1; i < arr.size(); ++i) {
                tail.next = new Node(arr.get(i));
                tail = tail.next;
            }

            Solution ob = new Solution();
            Node[] result = ob.alternatingSplitList(head);
            printList(result[0]);
            printList(result[1]);
        }

        sc.close();
    }
}

// } Driver Code Ends


// User function Template for Java
/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
    // Function to append a new node with newData at the end of a linked list
    Node[] alternatingSplitList(Node head) {
        // code here
        Node[] sol=new Node[2];
        Node temp=head, one =new Node(0), two =new Node(0), first=one, second=two;
        int i=0;
        while(temp!=null){
            if(i%2==1){
                one.next=new Node(temp.data);
                one=one.next;
                temp=temp.next;
            }
            else{
                two.next=new Node(temp.data);
                two=two.next;
                temp=temp.next;
            }
            i++;
        }
        first=first.next;
        second=second.next;
        sol[0]=second;
        sol[1]=first;
        return sol;
    }
}
