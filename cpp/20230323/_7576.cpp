#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int M, N, H, tomato_count, day = 0;
vector<vector<vector<int>>> box;
int di[] = {1, -1, 0, 0, 0, 0};
int dj[] = {0, 0, 1, -1, 0, 0};
int dk[] = {0, 0, 0, 0, 1, -1};

void bfs()
{
	queue<pair<int, pair<int, int>>> q;

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				if (box[i][j][k] == 1)
					q.push(make_pair(i, make_pair(j, k)));
			}
		}
	}

	while (!q.empty())
	{
		pair<int, pair<int, int>> crr = q.front();
		q.pop();

		for(int l = 0; l < 6; l++)
		{
			int new_i = crr.first + di[l];
			int new_j = crr.second.first + dj[l];
			int new_k = crr.second.second + dk[l];
			if (new_i >= 0 && new_i < H && new_j >= 0 && new_j < N && new_k >= 0 && new_k < M)
			{
				if (box[new_i][new_j][new_k] == 0)
				{
					tomato_count--;
					box[new_i][new_j][new_k] = box[crr.first][crr.second.first][crr.second.second] + 1;
					q.push(make_pair(new_i, make_pair(new_j, new_k)));
					day = max(day, box[new_i][new_j][new_k]) - 1;
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

	H = 1;
	cin >> M >> N;
	box = vector<vector<vector<int>>>(H, vector<vector<int>>(N, vector<int>(M, 0)));

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				cin >> box[i][j][k];
				if (box[i][j][k] == 0)
					tomato_count++;
			}
		}
	}

	bfs();
	if (tomato_count == 0)
		cout << day << '\n';
	else
		cout << "-1\n";
}