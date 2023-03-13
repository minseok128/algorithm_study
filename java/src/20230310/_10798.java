import java.util.Scanner;

public class _10798 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String[] input = new String[5];

		for (int i = 0; i < 5; i++) {
			input[i] = sc.nextLine();
		}
		for (int i = 0; i < 15; i++) {
			for (int j = 0; j < 5; j++) {
				if (i < input[j].length()) {
					System.out.print(input[j].charAt(i));
				}
			}
		}
		System.out.print('\n');
		sc.close();
		return;
	}
}
