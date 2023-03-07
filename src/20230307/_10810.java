import java.util.Scanner;

public class _10810 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int s, e, v;
		int N = sc.nextInt();
		int M = sc.nextInt();
		int[] arr = new int[N];

		for (int i = 0; i < M; i++) {
			s = sc.nextInt();
			e = sc.nextInt();
			v = sc.nextInt();
			for (int j = s; j <= e; j++) {
				arr[j - 1] = v;
			}
		}
		for (int i = 0; i < arr.length; i++) {
			System.out.print(arr[i]);
			if (i != arr.length - 1)
				System.out.print(" ");
		}
		System.out.print('\n');
		sc.close();
	}
}
