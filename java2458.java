/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    static final int[] maxi = new int[100001];
    int curr = 0;
    public int[] treeQueries(TreeNode root, int[] queries) {
        traverseLeftToRight(root, 0);
        curr = 0; 
        traverseRightToLeft(root, 0);
        int queryCount = queries.length;
        int[] queryResults = new int[queryCount];
        for (int i = 0; i < queryCount; i++) queryResults[i] = maxi[queries[i]];

        return queryResults;
    }
    private void traverseLeftToRight(TreeNode node, int currentHeight) {
        if (node == null) return;
        maxi[node.val] = curr;
        curr = Math.max(curr, currentHeight);
        traverseLeftToRight(node.left, currentHeight + 1);
        traverseLeftToRight(node.right, currentHeight + 1);
    }

    private void traverseRightToLeft(TreeNode node, int currentHeight) {
        if (node == null) return;
        maxi[node.val] = Math.max(
            maxi[node.val],
            curr
        );
        curr = Math.max(currentHeight, curr);

        traverseRightToLeft(node.right, currentHeight + 1);
        traverseRightToLeft(node.left, currentHeight + 1);
    }
}
