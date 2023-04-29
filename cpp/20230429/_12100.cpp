#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;

typedef struct ele
{
	int v;
	char c;
} Ele;

int N, dy[][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, 1}}, dx[][2] = {{0, 1}, {0, 1}, {-1, 0}, {1, 0}}, res = 1;

void print_map(vector<vector<Ele>> map)
{
	for (int i = 1; i < N + 1; i++)
	{
		for (int j = 1; j < N + 1; j++)
			cout << setw(4) << right << map[i][j].v << " ";
		cout << '\n';
	}
}

void move(int d, vector<vector<Ele>> &map)
{
	for (int i = 1; i < N + 1; i++)
		for (int j = 1; j < N + 1; j++)
			map[i][j].c = 0;
	int sy, sx;
	if (d < 2)
	{
		sy = d == 0 ? 2 : N - 1;
		sx = 1;
	}
	else
	{
		sy = 1;
		sx = d == 2 ? N - 1 : 2;
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N - 1; j++)
		{
			int new_y = sy + dy[d][0] * j, new_x = sx + dx[d][0] * j;
			for (int tmp = 1; tmp <= N; tmp++)
			{
				int tmp_y = new_y + dy[d][0] * tmp * -1, tmp_x = new_x + dx[d][0] * tmp * -1;
				if (map[tmp_y][tmp_x].v)
				{
					if (map[tmp_y][tmp_x].v == map[sy + dy[d][0] * j][sx + dx[d][0] * j].v && !map[tmp_y][tmp_x].c)
					{
						map[tmp_y][tmp_x].v <<= 1;
						map[tmp_y][tmp_x].c = 1;
						map[new_y][new_x].v = 0;
						map[new_y][new_x].c = 0;
					}
					else if (tmp > 1)
					{
						tmp_y += dy[d][0];
						tmp_x += dx[d][0];
						map[tmp_y][tmp_x].v = map[new_y][new_x].v;
						map[tmp_y][tmp_x].c = 0;
						map[new_y][new_x].v = 0;
						map[new_y][new_x].c = 0;
					}
					break;
				}
			}
		}
		sy += dy[d][1];
		sx += dx[d][1];
	}
}

void recursive(vector<vector<Ele>> map, int n)
{
	if (n == 5)
	{
		for (int i = 1; i < N + 1; i++)
		{
			for (int j = 1; j < N + 1; j++)
				res = max(res, map[i][j].v);
		}
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		vector<vector<Ele>> tmp_map(map);
		move(i, tmp_map);
		recursive(tmp_map, n + 1);
	}
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	cin >> N;
	vector<vector<Ele>> map(N + 2, vector<Ele>(N + 2, {3, 0}));
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			cin >> map[i][j].v;
			map[i][j].c = 0;
		}
	recursive(map, 0);
	cout << res << '\n';
}