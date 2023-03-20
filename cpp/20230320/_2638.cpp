#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M, cheese;
int dyA[] = {1, -1, 0, 0};
int dxA[] = {0, 0, 1, -1};
int mode[4][5] = { {0, 1, 0, 0, 0}, {0, 1, 0, 0, -1}, {0, 0, 0, 1, 0}, {0, 0, -1, 1, 0} };
queue<pair<int, int>> q;
char map[100][100];

void bfs_unit(int a, int b)
{
	q.push(make_pair(a, b));
	
	while (!q.empty())
	{
		pair<int, int> crr = q.front();
		map[crr.first][crr.second] = '#';
		q.pop();
		for (int j = 0; j < 4; j++)
		{
			int new_y = crr.first + dyA[j];
			int new_x = crr.second + dxA[j];
			if (new_y >= 0 && new_y < N && new_x >= 0 && new_x < M)
			{
				if (map[new_y][new_x] == '0')
				{
					map[new_y][new_x] = '#';
					q.push(make_pair(new_y, new_x));
				}
			}
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	cin >> N >> M;
	mode[0][0] = N;
	mode[1][0] = N;
	mode[2][0] = M;
	mode[3][0] = M;
	mode[1][4] += M;
	mode[3][2] += N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == '1')
				cheese++;
		}
	}


	for (int m = 0; m < 4; m++)
	{
		for (int i = 0; i < mode[m][0]; i++)
		{
			if (map[i * mode[m][1] + mode[m][2]][i * mode[m][3] +  mode[m][4]] == '0')
			{
				bfs_unit(i * mode[m][1] + mode[m][2], i * mode[m][3] +  mode[m][4]);
			}
		}
	}

	int result = 0;
	for (result = 0; cheese != 0; result++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (map[i][j] == '1')
				{
					int count = 0;
					for (int k = 0; k < 4; k++)
					{
						int new_y = i + dyA[k];
						int new_x = j + dxA[k];
						if (new_y == -1 || new_y == N || new_x == -1 || new_x == M)
							count++;
						else if (new_y >= 0 && new_y < N && new_x >= 0 && new_x < M)
							if (map[new_y][new_x] == '#')
								count++;
					}
					if (count >= 2)
					{
						cheese -= 1;
						map[i][j] = '2';
					}
				}
			}
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (map[i][j] == '2')
				{
					bfs_unit(i ,j);
				}
			}
		}
	}
	cout << result << '\n';
}