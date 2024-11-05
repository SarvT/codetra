//charm
//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.lang.*;
import java.util.*;

class DriverClass {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            int n = sc.nextInt();
            int[][] arr = new int[n][n];

            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++) arr[i][j] = sc.nextInt();

            GFG g = new GFG();
            g.rotate(arr);
            printMatrix(arr);

            System.out.println("~");
        }
    }

    static void printMatrix(int arr[][]) {
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr[0].length; j++) System.out.print(arr[i][j] + " ");
            System.out.println("");
        }
    }
}
// } Driver Code Ends


// User function Template for Java

class GFG {
    static void rotate(int mat[][]) {
        // Code Here
        int n=mat.length, m=mat[0].length;
        // 0,0--0,m-1       0,1--1, m-1     0,m-1--m-1, m-1
        // 1,0--0,m-2       1,1--1, m-2     1,2--2, m-2
        int [][]newMat = new int[n][m];
        for(int i=0; i<n; i++){
            int k=m-(i+1);
            for(int j=0; j<m; j++) newMat[j][k] = mat[i][j];
        }
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++) mat[i][j] = newMat[i][j];
        
        
        
        
    }
}
