#include <iostream>
#include <queue>
#include <vector>
using namespace std;

char map[1000][1000];
short N, M, K, sy, sx, ey, ex;
const int dy[] = {1, -1, 0, 0, 0};
const int dx[] = {0, 0, 1, -1, 0};

typedef struct Me
{
	short y;
	short x;
	int count;
	char mode;
	char best;
	Me(short Y, short X, int Count, char Mode, char Best) : y(Y), x(X), count(Count), mode(Mode), best(Best) {}
} Me;

int bfs()
{
	char best;
	queue<Me> q;
	vector<vector<int>> is_cheacked(N, vector<int>(M, -1));
	q.push(Me(sy, sx, 0, (char)5, (char)0));

	while (!q.empty())
	{
		Me crr = q.front();
		q.pop();

		if (is_cheacked[crr.y][crr.x] == -1 || is_cheacked[crr.y][crr.x] > crr.count)
		{
			// cout << "move:" << crr.y << " " << crr.x << '\n';
			is_cheacked[crr.y][crr.x] = crr.count;

			for (int i = 0; i < 4; i++)
			{
				int new_k = 0;
				for (int j = 1; j <= K; j++)
				{
					if (!(crr.y + dy[i] * j >= 0 && crr.y + dy[i] * j < N && crr.x + dx[i] * j >= 0 && crr.x + dx[i] * j < M))
					{
						new_k = j - 1;
						break;
					}
					if (map[crr.y + dy[i] * j][crr.x + dx[i] * j] == '#')
					{
						new_k = j - 1;
						break;
					}
					new_k = j;
				}
				for (int j = new_k; j > 0; j--)
				{
					int new_y = crr.y + dy[i] * j;
					int new_x = crr.x + dx[i] * j;
					if ((crr.mode != i || crr.best) && dx[crr.mode] * dx[i] != -1 && dy[crr.mode] * dy[i] != -1)
					{
						if (new_y == ey && new_x == ex)
						{
							// cout << "here:" << new_y << " " << new_x << '\n';
							return (crr.count + 1);
						}
						best = j == new_k ? 1 : 0;
						q.push(Me(new_y, new_x, crr.count + 1, i, best));
					}
				}
			}
		}
	}
	return (-1);
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}
	cin >> sy >> sx >> ey >> ex;
	sx -= 1;
	sy -= 1;
	ex -= 1;
	ey -= 1;
	// cout << "dest:" << ey << " " << ex << '\n';
	cout << bfs() << '\n';
}
