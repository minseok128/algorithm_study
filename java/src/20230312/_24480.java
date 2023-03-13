import java.util.Scanner;
import java.util.List;
import java.util.Comparator;
import java.util.ArrayList;
import java.util.Stack;

class Node {
	public int id;
	List<Node> nexts = new ArrayList<>();

	public Node(int id) {
		this.id = id;
	}

	public void addNext(Node next) {
		this.nexts.add(next);
	}

	public void sortNexts() {
		this.nexts.sort(new Comparator<Node>() {
			@Override
			public int compare(Node a, Node b) {
				if (a.id > b.id)
					return (1);
				else if (a.id == b.id)
					return (0);
				else
					return (-1);
			}
		});
	}
}

public class _24480 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int M = sc.nextInt();
		int R = sc.nextInt();
		int s, e;
		Node[] nodes = new Node[N + 1];
		boolean[] isCheaked = new boolean[N + 1];
		int[] orderArr = new int[N + 1];
		int order = 1;

		for (int i = 1; i < N + 1; i++) {
			nodes[i] = new Node(i);
		}
		for (int i = 0; i < M; i++) {
			s = sc.nextInt();
			e = sc.nextInt();
			nodes[s].addNext(nodes[e]);
			nodes[e].addNext(nodes[s]);
		}
		for (int i = 1; i <= N; i++)
			nodes[i].sortNexts();

		Stack<Node> stack = new Stack<>();
		stack.push(nodes[R]);
		while (!stack.isEmpty()) {
			Node crr = stack.pop();
			if (!isCheaked[crr.id]) {
				orderArr[crr.id] = order++;
				isCheaked[crr.id] = true;
				for (int j = 0; j < crr.nexts.size(); j++) {
					stack.push(crr.nexts.get(j));
				}
			}
		}
		for (int i = 1; i < orderArr.length; i++) {
			System.out.println(orderArr[i]);
		}
		sc.close();
	}
}