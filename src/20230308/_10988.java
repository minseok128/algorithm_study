import java.util.Scanner;

public class _10988 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String str = sc.next();
		int i = 0, j = str.length() - 1;
		while (i < j) {
			if (str.charAt(i) != str.charAt(j)) {
				System.out.println(0);
				sc.close();
				return;
			}
			i++;
			j--;
		}
		System.out.println(1);
		sc.close();
		return;
	}
}
