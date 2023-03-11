import java.util.Scanner;
import java.util.Queue;
import java.util.LinkedList;

class Pair {
	public int bx;
	public int by;
	public int x;
	public int y;
	public int count;

	Pair(int x, int y, int bx, int by, int count) {
		this.x = x;
		this.y = y;
		this.bx = bx;
		this.by = by;
		this.count = count;
	}
}

public class _13459 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int M = sc.nextInt();
		int count = 0;
		boolean flag = false;
		char[][] arr = new char[N][M];
		boolean[][][][] visited = new boolean[N][M][N][M];
		Queue<Pair> q = new LinkedList<>();
		Pair sp = new Pair(0, 0, 0, 0, 0);
		String str;
		for (int i = 0; i < N; i++) {
			str = sc.next();
			for (int j = 0; j < M; j++) {
				arr[i][j] = str.charAt(j);
				if (arr[i][j] == 'R') {
					sp.y = i;
					sp.x = j;
					arr[i][j] = '.';
				}
				if (arr[i][j] == 'B') {
					sp.by = i;
					sp.bx = j;
					arr[i][j] = '.';
				}
			}
		}
		sc.close();

		q.add(sp);
		while (!q.isEmpty() && !flag) {
			Pair crr = q.poll();
			if (crr.count > 10)
				break;
			for (int k = 0; k < 4; k++) {
				Pair next = nextPair(k, crr, arr);
				if (next.x == 0) {
					flag = true;
					count = next.count;
					break;
				} else if (next.x == -1)
					continue;
				if (visited[next.y][next.x][next.by][next.bx] == false) {
					visited[next.y][next.x][next.by][next.bx] = true;
					q.add(next);
				}
			}
		}
		if (count == 0 || count > 10)
			System.out.println(0);
		else
			System.out.println(1);
	}

	public static Pair nextPair(int type, Pair now, char[][] arr) {
		Pair newPair = new Pair(now.x, now.y, now.bx, now.by, now.count + 1);
		int dx = 0, dy = 0;
		boolean flag1 = false, flag2 = false;
		if (type == 0)
			dy = 1;
		else if (type == 1)
			dy = -1;
		else if (type == 2)
			dx = 1;
		else
			dx = -1;
		while (!(flag1 && flag2)) {
			flag1 = false;
			flag2 = false;
			if (newPair.x != 0 && newPair.bx != 0 && arr[newPair.y + dy][newPair.x + dx] == '.'
					&& !(newPair.y + dy == newPair.by && newPair.x + dx == newPair.bx)) {
				newPair.y += dy;
				newPair.x += dx;
			} else if (newPair.x != 0 && newPair.bx != 0 && arr[newPair.y + dy][newPair.x + dx] == 'O') {
				flag1 = true;
				newPair.x = 0;
				newPair.y = 0;
			} else
				flag1 = true;
			if (newPair.x != 0 && newPair.bx != 0 && arr[newPair.by + dy][newPair.bx + dx] == '.'
					&& !(newPair.by + dy == newPair.y && newPair.bx + dx == newPair.x)) {
				newPair.by += dy;
				newPair.bx += dx;
			} else if (newPair.x == 0 && arr[newPair.by + dy][newPair.bx + dx] == '.') {
				newPair.by += dy;
				newPair.bx += dx;
			} else if (arr[newPair.by + dy][newPair.bx + dx] == 'O') {
				return (new Pair(-1, -1, -1, -1, -1));
			} else
				flag2 = true;
		}
		return (newPair);
	}
}