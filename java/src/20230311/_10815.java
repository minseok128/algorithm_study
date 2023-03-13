import java.util.HashSet;
import java.util.Scanner;

public class _10815 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		HashSet<Integer> set = new HashSet<Integer>();
		Integer key;

		for (int i = 0; i < N; i++) {
			key = sc.nextInt();
			set.add(key);
		}
		N = sc.nextInt();
		for (int i = 0; i < N; i++) {
			key = sc.nextInt();
			if (set.contains(key)) {
				System.out.print("1");
			} else
				System.out.print("0");
			if (i < N - 1)
				System.out.print(' ');
			else
				System.out.print('\n');
		}
		sc.close();
		return;
	}
}
