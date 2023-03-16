import java.util.*;

public class _2920 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String input = sc.nextLine();
		switch (input) {
			case "1 2 3 4 5 6 7 8":
				System.out.println("ascending");
				break;
			case "8 7 6 5 4 3 2 1":
				System.out.println("descending");
				break;
			default:
				System.out.println("mixed");

		}
		sc.close();
	}
}
