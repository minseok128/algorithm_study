import java.util.TreeSet;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Scanner;

public class _1764 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int M = sc.nextInt();
		int count = 0;
		HashSet<String> set0 = new HashSet<String>();
		HashSet<String> set1 = new HashSet<String>();
		TreeSet<String> set2 = new TreeSet<String>();
		String key;

		for (int i = 0; i < N; i++) {
			key = sc.next();
			set0.add(key);
		}
		for (int i = 0; i < M; i++) {
			key = sc.next();
			set1.add(key);
		}
		Iterator<String> iter = set0.iterator();
		while (iter.hasNext()) {
			key = iter.next();
			if (set1.contains(key)) {
				set2.add(key);
				count++;
			}
		}
		System.out.println(count);
		iter = set2.iterator();
		while (iter.hasNext()) {
			System.out.println(iter.next());
		}
		sc.close();
		return;
	}
}
