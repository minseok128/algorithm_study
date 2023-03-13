import java.util.Scanner;
import java.util.Stack;

class Pair {
	public int y;
	public int x;

	Pair(int y, int x) {
		this.y = y;
		this.x = x;
	}
}

public class _27737 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int M = sc.nextInt();
		int K = sc.nextInt();
		int count = 0;
		int result = 0;
		int[][] arr = new int[N][N];
		Stack<Pair> s = new Stack<>();

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				arr[i][j] = sc.nextInt();
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (arr[i][j] == 0) {
					count = 0;
					s.add(new Pair(i, j));
					while (!s.isEmpty()) {
						Pair crr = s.pop();
						if (arr[crr.y][crr.x] == 0) {
							arr[crr.y][crr.x] = 1;
							count++;
							for (int k = 0; k < 4; k++) {
								int dy = 0, dx = 0;
								if (k == 0)
									dy = 1;
								else if (k == 1)
									dy = -1;
								else if (k == 2)
									dx = 1;
								else
									dx = -1;
								if (crr.y + dy >= 0 && crr.y + dy < N
										&& crr.x + dx >= 0 && crr.x + dx < N
										&& arr[crr.y + dy][crr.x + dx] == 0) {
									s.add(new Pair(crr.y + dy, crr.x + dx));
								}
							}
						}
					}
					if (count % K == 0)
						result += count / K;
					else
						result += count / K + 1;
				}
			}
		}
		if (result == 0)
			System.out.println("IMPOSSIBLE");
		else if (M - result >= 0) {
			System.out.println("POSSIBLE");
			System.out.println(M - result);
		} else
			System.out.println("IMPOSSIBLE");
		sc.close();
	}
}