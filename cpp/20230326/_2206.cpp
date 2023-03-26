#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int N, M;
vector<vector<vector<int>>> map;
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};

void print_map(int id)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << (char)(map[i][j][id] + 'A') << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

int bfs()
{
	queue<pair<pair<int, int>, int>> q;
	q.push(make_pair(make_pair(0, 0), 0));

	while (!q.empty())
	{
		pair<pair<int, int>, int> crr = q.front();
		q.pop();

		for (int k = 0; k < 4; k++)
		{
			int new_y = crr.first.first + dy[k];
			int new_x = crr.first.second + dx[k];

			if (new_y >= 0 && new_y < N && new_x >= 0 && new_x < M)
			{
				if (crr.second == 0)
				{
					if (map[new_y][new_x][0] != -1 && (map[new_y][new_x][0] == 0 || map[crr.first.first][crr.first.second][0] + 1 < map[new_y][new_x][0]))
					{
						map[new_y][new_x][0] = map[crr.first.first][crr.first.second][0] + 1;
						q.push(make_pair(make_pair(new_y, new_x), 0));
					}
					else if (map[new_y][new_x][0] == -1 && (map[new_y][new_x][1] == -1 || map[crr.first.first][crr.first.second][1] + 1 < map[new_y][new_x][1]))
					{
						map[new_y][new_x][1] = map[crr.first.first][crr.first.second][0] + 1;
						q.push(make_pair(make_pair(new_y, new_x), 1));
					}
				}
				else if (crr.second == 1)
				{
					if (map[new_y][new_x][1] != -1 && (map[new_y][new_x][1] == 0 || map[crr.first.first][crr.first.second][1] + 1 < map[new_y][new_x][1]))
					{
						map[new_y][new_x][1] = map[crr.first.first][crr.first.second][1] + 1;
						q.push(make_pair(make_pair(new_y, new_x), 1));
					}
				}
			}
		}
	}
	//print_map(0);
	//print_map(1);
	if (map[N - 1][M - 1][0] == 0 && map[N - 1][M - 1][1] == 0)
		return (-2);
	if (map[N - 1][M - 1][0] == 0)
		return (map[N - 1][M - 1][1]);
	if (map[N - 1][M - 1][1] == 0)
		return (map[N - 1][M - 1][0]);
	return (map[N - 1][M - 1][1] > map[N - 1][M - 1][0] ? map[N - 1][M - 1][0] : map[N - 1][M - 1][1]);
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	cin >> N >> M;
	map =  vector<vector<vector<int>>>(N, vector<vector<int>>(M, vector<int>(2)));
	string str;

	for (int i = 0; i < N; i++)
	{
		cin >> str;
		for (int j = 0; j < M; j++)
		{
			map[i][j][0] = str[j] - '0';
			map[i][j][1] = str[j] - '0';
			if (map[i][j][0] == 1)
			{
				map[i][j][0] = -1;
				map[i][j][1] = -1;
			}
		}
	}

	if (N * M == 1)
	{
		cout << '1' << '\n';
		return (0);
	}
	int result = bfs() + 1;
	cout << result << '\n';
}