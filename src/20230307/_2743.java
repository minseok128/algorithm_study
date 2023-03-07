import java.util.Scanner;

public class _2743 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		String str;

		for (int i = 0; i < N; i++) {
			str = sc.next();
			System.out.print(str.charAt(0));
			System.out.println(str.charAt(str.length() - 1));
		}
		sc.close();
	}
}
