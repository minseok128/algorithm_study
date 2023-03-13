import java.util.Scanner;

public class _2563 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int[][] arr = new int[101][101];
		int result = 0, x, y, N;

		N = sc.nextInt();
		for (int i = 0; i < N; i++) {
			x = sc.nextInt();
			y = sc.nextInt();
			for (int j = 0; j < 10; j++) {
				for (int k = 0; k < 10; k++) {
					if (arr[j + x][k + y] == 0) {
						arr[j + x][k + y] = 1;
						result++;
					}
				}
			}
		}
		System.out.println(result);
		sc.close();
		return;
	}
}
