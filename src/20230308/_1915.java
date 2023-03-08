import java.util.Scanner;

public class _1915 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt(), m = sc.nextInt();
		int dp[][] = new int[n][m];
		String str;
		int max = 0;

		for (int i = 0; i < n; i++) {
			str = sc.next();
			for (int j = 0; j < m; j++) {
				// System.out.println(str);
				dp[i][j] = str.charAt(j) - '0';
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (i != 0 && j != 0 && dp[i][j] > 0) {
					dp[i][j] = min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1;
				}
				if (dp[i][j] > max) {
					max = dp[i][j];
				}
			}
		}
		System.out.println(max * max);
		sc.close();
	}

	public static int min(int a, int b, int c) {
		if (a > b) {
			if (b > c)
				return (c);
			else
				return (b);
		} else {
			if (a > c)
				return (c);
			else
				return (a);
		}
	}
}
