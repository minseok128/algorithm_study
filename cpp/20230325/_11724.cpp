#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, num;
vector<vector<int>> roads;
vector<int> result;

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	result = vector<int>(N, 0);
	roads = vector<vector<int>>(N, vector<int>());
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		roads[a - 1].push_back(b - 1);
		roads[b - 1].push_back(a - 1);
	}

	queue<int> q;
	for (int i = 0; i < N; i++)
	{
		if (result[i] == 0)
		{
			num++;
			q.push(i);
			result[i] = num;

			while (!q.empty())
			{
				int crr = q.front();
				q.pop();

				for (int j = 0; j < roads[crr].size(); j++)
				{
					if (result[roads[crr][j]] == 0)
					{
						result[roads[crr][j]] = num;
						q.push(roads[crr][j]);
					}
				}
			}
		}
	}
	cout << num << '\n';
}