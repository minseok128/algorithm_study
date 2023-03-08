import java.util.Scanner;

public class _10813 {
	public static void main(String[] av) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[] arr = new int[N];
		int M = sc.nextInt();
		int a, b, temp;

		for (int i = 0; i < N; i++) {
			arr[i] = i + 1;
		}
		for (int i = 0; i < M; i++) {
			a = sc.nextInt() - 1;
			b = sc.nextInt() - 1;
			temp = arr[a];
			arr[a] = arr[b];
			arr[b] = temp;
		}
		for (int i = 0; i < N; i++) {
			System.out.print(arr[i]);
			if (i != N - 1)
				System.out.print(' ');
			else
				System.out.print('\n');
		}
		sc.close();
	}
}
