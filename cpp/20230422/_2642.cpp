#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> cube(6);
int map[8][8], sx, sy = -1, r1, r2[] = {5, 3, 4, 1, 2, 0}, dy[] = {-1, 0, 1, 0}, dx[] = {0, -1, 0, 1};
int info[6][4] = {{3, 4, 1, 2}, {0, 4, 5, 2}, {0, 1, 5, 3}, {0, 2, 5, 4}, {0, 3, 5, 1}, {1, 4, 3, 2}};

typedef struct ele
{
	int y, x, num, pn, ps;
	ele(int Y, int X, int N, int PN, int S) : y(Y), x(X), num(N), pn(PN), ps(S){};
} Ele;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	for (int i = 1; i < 7; i++)
		for (int j = 1; j < 7; j++)
		{
			cin >> map[i][j];
			if (sy == -1 && map[i][j] != 0)
			{
				sy = i;
				sx = j;
			}
		}

	queue<Ele> q;
	q.push(Ele(sy, sx, 0, 3, 0));
	cube[0].first = 7;
	cube[0].second = map[sy][sx];
	while (!q.empty())
	{
		Ele crr = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int new_y = crr.y + dy[i], new_x = crr.x + dx[i], tmp = 0;
			for (int j = 0; j < 4; j++)
				if (info[crr.num][j] == crr.pn)
					tmp = j;
			int new_num = info[crr.num][(i + tmp + crr.ps) % 4];

			if (map[new_y][new_x] != 0 && cube[new_num].first != 7)
			{
				if (map[new_y][new_x] == 1)
					r1 = new_num;
				cube[new_num].first = 7;
				cube[new_num].second = map[new_y][new_x];
				q.push(Ele(new_y, new_x, new_num, crr.num, (i + 2 * (i % 2 == 0)) % 4));
			}
		}
	}
	for (int i = 0; i < 6; i++)
		if (cube[i].first == 0)
		{
			cout << "0\n";
			return (0);
		}
	cout << cube[r2[r1]].second << '\n';
}