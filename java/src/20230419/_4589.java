import java.util.Scanner;

public class Main {
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);

		int n, a, b, c;
		System.out.println("Gnomes:");
		for (n = sc.nextInt(); n > 0; n--)
		{
			a = sc.nextInt();
			b = sc.nextInt();
			c = sc.nextInt();
			if ((a <= b && b <= c) || (a >= b && b >= c))
				System.out.println("Ordered");
			else
				System.out.println("Unordered");
		}
		sc.close();
	}
}