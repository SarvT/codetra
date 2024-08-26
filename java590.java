// worked
/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    public void postOrder(Node root, List<Integer> list){
        if(root==null) return;
        for(Node chl:root.children)postOrder(chl, list);
        list.add(root.val);
    }
    public List<Integer> postorder(Node root) {
        List<Integer> list = new ArrayList<>();
        postOrder(root, list);
        return list;
    }
}


// not worked
/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    public void postOrder(Node root, List<Integer> list){
        if(root==null) return;
        postOrder(root.children, list);
        postOrder(root.children, list);
        list.add(root.val);
    }
    public List<Integer> postorder(Node root) {
        List<Integer> list = new List<>();
        postOrder(root, list);
        return list;
    }
}
