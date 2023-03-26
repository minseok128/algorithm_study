#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};

int bfs()
{
	int M, N, K, y, x, result = 0;

	cin >> M >> N >> K;
	vector<vector<int>> map(N, vector<int>(M, 0));

	for (int i = 0; i < K; i++)
	{
		cin >> x >> y;
		map[y][x] = -1;
	}

	queue<pair<int, int>> q;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == -1)
			{
				result ++;
				q.push(make_pair(i, j));

				while (!q.empty())
				{
					pair<int, int> crr = q.front();
					q.pop();

					for (int k = 0; k < 4; k++)
					{
						int new_y = crr.first + dy[k];
						int new_x = crr.second + dx[k];

						if (new_y >= 0 && new_y < N && new_x >= 0 && new_x < M)
						{
							if (map[new_y][new_x] == -1)
							{
								map[new_y][new_x] = result;
								q.push(make_pair(new_y, new_x));
							}
						}
					}
				}
			}
		}
	}
	return (result);
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cout << bfs() << '\n';
	}
}