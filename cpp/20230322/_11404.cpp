#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<vector<int>> Nodes;
vector<vector<int>> result;

void find(int s)
{
	queue<int> q;

	q.push(s);
	while (!q.empty())
	{
		int crr = q.front();
		q.pop();

		for (int i = 0; i < N; i++)
		{
			if (i != crr && i != s && Nodes[crr][i] != 0)
			{
				if ((Nodes[crr][i] + result[s][crr] < result[s][i]) || result[s][i] == 0)
				{
					result[s][i] = Nodes[crr][i] + result[s][crr];
					q.push(i);
				}
			}
		}
	}
}

int main()
{
	cin >> N >> M;

	Nodes = vector<vector<int>>(N, vector<int>(N, 0));
	result = vector<vector<int>>(N, vector<int>(N, 0));
	for (int i = 0; i < M; i++)
	{
		int s, e, v;
		cin >> s >> e >> v;
		if (Nodes[s - 1][e - 1] == 0)
			Nodes[s - 1][e - 1] = v;
		else
			Nodes[s - 1][e - 1] = min(v, Nodes[s - 1][e - 1]);
	}
	for (int i = 0; i < N; i++)
	{
		find(i);
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << result[i][j] << ' ';
		}
		cout << '\n';
	}
}