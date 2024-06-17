//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            int p1[] = new int[2];
            int q1[] = new int[2];
            int p2[] = new int[2];
            int q2[] = new int[2];
            String S1[] = read.readLine().split(" ");
            p1[0] = Integer.parseInt(S1[0]);
            p1[1] = Integer.parseInt(S1[1]);
            q1[0] = Integer.parseInt(S1[2]);
            q1[1] = Integer.parseInt(S1[3]);
            String S2[] = read.readLine().split(" ");
            p2[0] = Integer.parseInt(S2[0]);
            p2[1] = Integer.parseInt(S2[1]);
            q2[0] = Integer.parseInt(S2[2]);
            q2[1] = Integer.parseInt(S2[3]);
            Solution ob = new Solution();
            String ans = ob.doIntersect(p1, q1, p2, q2);
            // if(ans)
            System.out.println(ans);
            // else
            // System.out.println("false");
        }
    }
}
// } Driver Code Ends

class Solution {

class Point {
        int x, y;
        Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

private int direction(Point p, Point q, Point r) {
    long val = (long)(q.y - p.y) * (r.x - q.x) - (long)(q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0; 
    return (val > 0) ? 1 : 2; 
}


    private boolean onSegment(Point p, Point q, Point r) {
        if (q.x <= Math.max(p.x, r.x) && q.x >= Math.min(p.x, r.x) &&
            q.y <= Math.max(p.y, r.y) && q.y >= Math.min(p.y, r.y)) {
            return true;
        }
        return false;
    }

    private boolean isIntersect(Point a1, Point b1, Point a2, Point b2) {
        int d1 = direction(a1, b1, a2);
        int d2 = direction(a1, b1, b2);
        int d3 = direction(a2, b2, a1);
        int d4 = direction(a2, b2, b1);

        if (d1 != d2 && d3 != d4) return true;

        if (d1 == 0 && onSegment(a1, a2, b1)) return true;
        if (d2 == 0 && onSegment(a1, b2, b1)) return true;
        if (d3 == 0 && onSegment(a2, a1, b2)) return true;
        if (d4 == 0 && onSegment(a2, b1, b2)) return true;
        return false;
    }
    
    String doIntersect(int p1[], int q1[], int p2[], int q2[]) {
        // code here
        Point a1 = new Point(p1[0], p1[1]);
        Point b1 = new Point(q1[0], q1[1]);
        Point a2 = new Point(p2[0], p2[1]);
        Point b2 = new Point(q2[0], q2[1]);

        return isIntersect(a1, b1, a2, b2) ? "true" : "false";
    }
}
