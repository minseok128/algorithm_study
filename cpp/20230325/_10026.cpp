#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
vector<vector<char>> origin_map;
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};

int bfs(int mode)
{
	int number = 0;
	queue<pair<int, int>> q;
	vector<vector<int>> map(N, vector<int>(N, 0));
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == 0)
			{
				number++;
				q.push(make_pair(i ,j));
				
				while (!q.empty())
				{
					pair<int, int> crr = q.front();
					q.pop();

					for (int k = 0; k < 4; k++)
					{
						int new_y = crr.first + dy[k];
						int new_x = crr.second + dx[k];

						if (new_y >= 0 && new_y < N && new_x >= 0 && new_x < N)
						{
							if ((mode == 0 && (map[new_y][new_x] == 0 && origin_map[new_y][new_x] == origin_map[crr.first][crr.second]))
								|| (mode == 1 && (map[new_y][new_x] == 0 && ((origin_map[new_y][new_x] == origin_map[crr.first][crr.second])
								|| (origin_map[new_y][new_x] * origin_map[crr.first][crr.second] == 5822)))))
							{
								map[new_y][new_x] = number;
								q.push(make_pair(new_y, new_x));
							}
						}
					}
				}
			}
		}
	}
	return (number);
}

int main ()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	cin >> N;
	origin_map = vector<vector<char>>(N, vector<char>(N));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> origin_map[i][j];
	}
	cout << bfs(0) << ' ' << bfs(1) << '\n';
}
