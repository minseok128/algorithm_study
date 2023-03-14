import java.util.*;

public class _1011 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		for (int i = 0; i < N; i++) {
			long s = sc.nextLong();
			long e = sc.nextLong();
			long len = e - s - 2;
			long total = 2, prev = 2;
			long k;
			for (k = 2; total < len; k++) {
				if (k % 2 == 1)
					prev++;
				total += prev;
				// System.out.println(total + "/" + k);
			}
			if (len < 0)
				System.out.println(1);
			else if (len == 0)
				System.out.println(2);
			else if (len == 2 || len == 1)
				System.out.println(3);
			else
				System.out.println(k + 1);
		}
		sc.close();
	}
}
