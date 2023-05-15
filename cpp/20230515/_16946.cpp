#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int N, M, dy[] = {1, -1, 0, 0}, dx[] = {0, 0, 1, -1};
vector<vector<int>> map;
vector<int> island_size;

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	string str;
	cin >> N >> M;
	map = vector<vector<int>>(N + 2, vector<int>(M + 2));
	for (int i = 0; i < N + 2; i++)
	{
		if (i != 0 && i != N + 1)
			cin >> str;
		for (int j = 0; j < M + 2; j++)
		{
			if (i == 0 || i == N + 1 || j == 0 || j == M + 1)
				map[i][j] = 1;
			else
				map[i][j] = str[j - 1] - '0';
		}
	}

	int cnt = 1, size;
	queue<pair<int, int>> q;
	for (int y = 1; y < N + 1; y++)
	{
		for (int x = 1; x < M + 1; x++)
		{
			if (map[y][x] == 0)
			{
				cnt++;
				size = 1;
				q.push({y , x});
				map[y][x] = cnt;
				while (!q.empty())
				{
					pair<int, int> crr = q.front();
					q.pop();
					
					for (int i = 0; i < 4; i++)
					{
						int new_y = crr.first + dy[i];
						int new_x = crr.second + dx[i];
						if (map[new_y][new_x] == 0)
						{
							size++;
							map[new_y][new_x] = cnt;
							q.push({new_y, new_x});
						}
					}
				}
				island_size.emplace_back(size);
			}
		}
	}
	int tmp_y, tmp_x;
	set<int> s;
	for (int i = 1; i < N + 1; i++)
	{
		for (int j = 1; j < M + 1; j++)
		{
			if (map[i][j] == 1)
			{
				size = 1;
				s.clear();
				for (int k = 0; k < 4; k++)
				{
					tmp_y = i + dy[k];
					tmp_x = j + dx[k];
					if (map[tmp_y][tmp_x] > 1)
						s.insert(map[tmp_y][tmp_x] - 2);
				}
				for (auto it = s.begin(); it != s.end(); it++)
					size += island_size[*it];
				cout << size % 10;
			}
			else 
				cout << '0';
		}
		cout << '\n';
	}
}