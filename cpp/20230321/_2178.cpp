#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int N, M;
vector<vector<int>> map;
int dyA[] = {1, -1, 0, 0};
int dxA[] = {0, 0, 1, -1};

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	cin >> N >> M;
	map = vector<vector<int>>(N, vector<int>(M));
	string s;
	for (int i = 0; i < N; i++)
	{
		cin >> s;
		for (int j = 0; j < M; j++)
		{
			map[i][j] = s[j] - '1';
		}
	}

	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	map[0][0] = 1;
	while (!q.empty())
	{
		pair<int, int> crr = q.front();
		q.pop();
		
		for (int k = 0; k < 4; k++)
		{
			int new_y = crr.first + dyA[k];
			int new_x = crr.second + dxA[k];
			if (new_y >= 0 && new_y < N && new_x >= 0 && new_x < M)
				if (map[new_y][new_x] == 0)
				{
					map[new_y][new_x] = map[crr.first][crr.second] + 1;
					if (new_y == N - 1 && new_x == M - 1)
					{
						cout << map[new_y][new_x] << '\n';
						return (0);
					}
					q.push(make_pair(new_y, new_x));
				}
		}
	}
}