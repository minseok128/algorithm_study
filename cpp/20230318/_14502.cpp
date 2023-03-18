#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M;

int bfs(vector<vector<int>> map)
{
	queue<pair<int, int>> q;
	vector<vector<bool>> is_cheacked(N, vector<bool>(M, false));
	int count = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 2 && !is_cheacked[i][j])
			{
				q.push(make_pair(i, j));
				map[i][j] = 0;

				while (!q.empty())
				{
					pair<int, int> crr;
					crr = q.front();
					q.pop();

					if (!is_cheacked[crr.first][crr.second] && map[crr.first][crr.second] == 0)
					{
						is_cheacked[crr.first][crr.second] = true;
						map[crr.first][crr.second] = 2;
						count++;

						for (int k = 0; k < 4; k++)
						{
							int dx = k == 0 ? -1 : (k == 1 ? 1 : 0);
							int dy = k == 2 ? -1 : (k == 3 ? 1 : 0);

							if (crr.first + dy >= 0 && crr.first + dy < N && crr.second + dx >= 0 && crr.second + dx < M)
								q.push(make_pair(crr.first + dy, crr.second + dx));
						}
					}
				}
			}
		}
	}
	return (count);
}

int make_new_map(vector<vector<int>> &map, int w1, int w2, int w3)
{
	if (map[w1 / M][w1 % M] == 0 && map[w2 / M][w2 % M] == 0 && map[w3 / M][w3 % M] == 0)
	{
		map[w1 / M][w1 % M] = 1;
		map[w2 / M][w2 % M] = 1;
		map[w3 / M][w3 % M] = 1;
		return (1);
	}
	return (0);
}

int main()
{
	int result = 0, safe = -3;
	cin >> N >> M;
	vector<vector<int>> map(N, vector<int>(M, 0));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 0 || map[i][j] == 2)
				safe++;
		}
	}
	for (int i = 0; i < N * M - 2; i++)
	{
		for (int j = i + 1; j < N * M - 1; j++)
		{
			for (int k = j + 1; k < N * M; k++)
			{
				vector<vector<int>> new_map(map);
				if (make_new_map(new_map, i, j, k))
				{
					result = safe - bfs(new_map) > result ? safe - bfs(new_map) : result;
				}
			}
		}
	}
	cout << result << '\n';
}
