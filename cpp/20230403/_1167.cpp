#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

vector<pair<int, int>> node[100001];
int checked[100001];

int V;

pair<int, int> bfs(int s)
{
	pair<int, int> result(s, 0);
	memset(checked, -1, sizeof(int) * (V + 1));
	queue<int> q;
	q.push(s);
	checked[s] = 0;
	while (!q.empty())
	{
		int crr = q.front();
		q.pop();

		for (int i = 0; i < node[crr].size(); i++)
		{
			int new_d = node[crr][i].first;
			int new_c = node[crr][i].second + checked[crr];
			if (checked[new_d] == -1)
			{
				checked[new_d] = new_c;
				if (result.second < new_c)
				{
					result.first = new_d;
					result.second = new_c;
				}
				q.push(new_d);
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
	
	cin >> V;
	int d, c, j;
	for (int i = 1; i <= V; i++)
	{
		cin >> j;
		while (1)
		{
			cin >> d;
			if (d == -1)
				break ;
			cin >> c;
			node[j].emplace_back(d, c);
		}
	}
	cout << bfs(bfs(1).first).second << '\n';
}