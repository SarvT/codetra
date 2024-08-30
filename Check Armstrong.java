import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		// Write your code here
		Scanner scr = new Scanner(System.in);
		int n=scr.nextInt();
		int cnt=0, i=0, dup=n;
		int[] arr = new int[450];
		while (n>0) {
			arr[i]=n%10;
			i++;
			n/=10;
			cnt++;
		}
		int ans = 0;
		for (int j = 0; j < cnt; j++) {
			ans+=Math.pow(arr[j], cnt);
		}
		if(ans==dup)System.out.print(true);
		else System.out.print(false);
		
	}
}
