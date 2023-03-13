import java.util.Scanner;

public class _2566 {
	public static void main(String[] av) {
		Scanner sc = new Scanner(System.in);
		int max = 0, x = 0, y = 0, tmp;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				tmp = sc.nextInt();
				if (tmp >= max) {
					y = i + 1;
					x = j + 1;
					max = tmp;
				}
			}
		}
		System.out.println(max);
		System.out.println(y + " " + x);
		sc.close();
	}
}
