#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

unsigned char map[10001][10001];
int checked[10001];
int N;

pair<int, int> bfs (int s)
{
	memset(checked, 0, sizeof(int) * (N + 1));
	checked[s] = 0;
	queue<int> q;
	q.push(s);
	pair<int, int> result = make_pair(s, 0);

	while (!q.empty())
	{
		int crr = q.front();
		q.pop();

		for (int i = 0; i < N; i++)
		{
			if (i != s && map[crr][i] != 0 && checked[i] == 0)
			{
				checked[i] = checked[crr] + map[crr][i];
				if (result.second < checked[i])
				{
					result.first = i;
					result.second = checked[i];
				}
				q.push(i);
			}
		}
	}
	return (result);
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int s, e, c;
	cin >> N;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> s >> e >> c;
		map[s - 1][e - 1] = c;
		map[e - 1][s - 1] = c;
	}
	
	cout << bfs((bfs(0)).first).second << '\n';
}
