import java.util.Scanner;

public class _10811 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int M, s, e, tmp;
		int[] arr = new int[N];

		for (int i = 0; i < N; i++) {
			arr[i] = i + 1;
		}
		M = sc.nextInt();
		for (int i = 0; i < M; i++) {
			s = sc.nextInt();
			e = sc.nextInt();
			while (s < e) {
				tmp = arr[s - 1];
				arr[s - 1] = arr[e - 1];
				arr[e - 1] = tmp;
				s++;
				e--;
			}
		}
		for (int i = 0; i < arr.length; i++) {
			System.out.print(arr[i]);
			if (i != arr.length - 1)
				System.out.print(' ');
			else
				System.out.print('\n');
		}
		sc.close();
	}
}
