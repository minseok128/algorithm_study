#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, jy, jx, fy = -1, fx = -1;
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};
int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> N >> M;
	vector<vector<char>> map(N, vector<char>(M));
	queue<pair<pair<char, int>, pair<int, int>>> q;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 'J')
			{
				jy = i;
				jx = j;
				map[i][j] = '0';
			}
			else if (map[i][j] == 'F')
			{
				q.push(make_pair(make_pair('F', 0), make_pair(i, j)));
			}
		}
	q.push(make_pair(make_pair('J', 0), make_pair(jy, jx)));
	while (!q.empty())
	{
		pair<pair<char, int>, pair<int, int>> crr = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int new_y = crr.second.first + dy[i];
			int new_x = crr.second.second + dx[i];
			if (new_y >= 0 && new_y < N && new_x >= 0 && new_x < M)
			{
				if (crr.first.first == 'F' && map[new_y][new_x] != 'F' && map[new_y][new_x] != '#')
				{
					map[new_y][new_x] = 'F';
					q.push(make_pair(make_pair('F', crr.first.second + 1), make_pair(new_y, new_x)));
				}
				else if (crr.first.first == 'J' && map[new_y][new_x] == '.')
				{
					map[new_y][new_x] = 'J';
					q.push(make_pair(make_pair('J', crr.first.second + 1), make_pair(new_y, new_x)));
				}
			}
			else if (crr.first.first == 'J')
			{
				cout << crr.first.second + 1 << '\n';
				return (0);
			}
		}
	}
	cout << "IMPOSSIBLE\n";
}