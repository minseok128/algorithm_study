import java.util.Scanner;

public class _20207 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int[] arr = new int[367];
		int N = sc.nextInt(), s, e, w, h, result = 0;

		for (int i = 0; i < N; i++) {
			s = sc.nextInt();
			e = sc.nextInt();
			for (int j = s; j <= e; j++) {
				arr[j]++;
			}
		}
		for (int i = 1; i <= 366; i++) {
			if (arr[i] > 0) {
				w = 0;
				h = arr[i];
				while (arr[i] > 0) {
					if (arr[i] > h)
						h = arr[i];
					i++;
					w++;
				}
				result += w * h;
			}
		}
		System.out.println(result);
		sc.close();
		return;
	}
}
