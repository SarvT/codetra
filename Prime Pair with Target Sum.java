//{ Driver Code Starts
import java.io.*;
import java.util.*;
import java.util.ArrayList;

class IntArray {
    public static int[] input(BufferedReader br, int n) throws IOException {
        String[] s = br.readLine().trim().split(" ");
        int[] a = new int[n];
        for (int i = 0; i < n; i++) a[i] = Integer.parseInt(s[i]);

        return a;
    }

    public static void print(int[] a) {
        for (int e : a) System.out.print(e + " ");
        System.out.println();
    }

    public static void print(ArrayList<Integer> a) {
        for (int e : a) System.out.print(e + " ");
        System.out.println();
    }
}

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t;
        t = Integer.parseInt(br.readLine());
        while (t-- > 0) {

            int n;
            n = Integer.parseInt(br.readLine());

            Solution obj = new Solution();
            ArrayList<Integer> res = obj.getPrimes(n);

            IntArray.print(res);
        }
    }
}

// } Driver Code Ends



class Solution {
    public static ArrayList<Integer> getPrimes(int n) {
        // code here
        int[] prime = new int[n + 1];
        Arrays.fill(prime, 1);
        prime[0] = prime[1] = 0;
        for (int i = 2; i <= Math.sqrt(n); i++) {
            if (prime[i] == 1) {
                for (int j = 2 * i; j <= n; j += i) {
                    prime[j] = 0;
                }
            }
        }
        
        ArrayList<Integer> primeList = new ArrayList<>();
        for (int i = 2; i <= n; i++) {
            if (prime[i] == 1) {
                primeList.add(i);
            }
        }
        
        int i = 0;
        int j = primeList.size() - 1;
        while (i <= j) {
            int sum = primeList.get(i) + primeList.get(j);
            if (sum == n) {
                ArrayList<Integer> result = new ArrayList<>();
                result.add(primeList.get(i));
                result.add(primeList.get(j));
                return result;
            } else if (sum > n) {
                j--;
            } else {
                i++;
            }
        }
        
        ArrayList<Integer> result = new ArrayList<>();
        result.add(-1);
        result.add(-1);
        return result;
    }
    }
}
