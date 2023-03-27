#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, K, result = -1;
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

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	cin >> N >> M >> K;
	map = vector<vector<vector<int>>>(N, vector<vector<int>>(M, vector<int>(K + 1)));
	string str;
	for (int i  = 0; i < N; i++)
	{
		cin >> str;
		for (int j = 0; j < M; j++)
		{
			for (int k = 0; k < K + 1; k++)
			{
				if (str[j] == '1')
					map[i][j][k] = -1;
				else
					map[i][j][k] = 0;
			}
		}
	}

	queue<pair<pair<int, int>, int>> q;
	q.push(make_pair(make_pair(0, 0), 0));

	while (!q.empty())
	{
		pair<pair<int, int>, int> crr = q.front();
		q.pop();
		if (crr.first.first == N - 1 && crr.first.second == M - 1)
		{
			if (result == -1)
					result = map[crr.first.first][crr.first.second][crr.second];
			else if (result > map[crr.first.first][crr.first.second][crr.second])
				result = map[crr.first.first][crr.first.second][crr.second];
		}
		for (int i = 0; i < 4; i++)
		{
			int new_y = crr.first.first + dy[i];
			int new_x = crr.first.second + dx[i];
			
			if (new_y >= 0 && new_y < N && new_x >= 0 && new_x < M)
			{
				if (map[new_y][new_x][crr.second] != -1
					&& (map[new_y][new_x][crr.second] > map[crr.first.first][crr.first.second][crr.second] + 1
					|| map[new_y][new_x][crr.second] == 0))
				{
					map[new_y][new_x][crr.second] = map[crr.first.first][crr.first.second][crr.second] + 1;
					q.push(make_pair(make_pair(new_y, new_x), crr.second));
				}
				if ((map[new_y][new_x][crr.second] == -1 && crr.second < K)
					&& (map[new_y][new_x][crr.second + 1] > map[crr.first.first][crr.first.second][crr.second + 1] + 1
					|| map[new_y][new_x][crr.second + 1] == -1))
				{
					map[new_y][new_x][crr.second + 1] = map[crr.first.first][crr.first.second][crr.second] + 1;
					q.push(make_pair(make_pair(new_y, new_x), crr.second + 1));
				}
			}
		}
	}
	if (result == -1)
		cout << "-1" << '\n';
	else
		cout << result + 1 << '\n';
}