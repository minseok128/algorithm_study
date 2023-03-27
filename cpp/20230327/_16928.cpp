#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int map[101][2] = {0};

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int N, M, s, e;
	cin >> N >> M;
	for (int i = 0; i < N + M; i++)
	{
		cin >> s >> e;
		map[s][1] = e;
	}

	queue<int> q;
	q.push(1);

	while (!q.empty())
	{
		int crr = q.front();
		q.pop();

		for (int i = 1; i <= 6; i++)
		{
			int new_i = crr + i;
			if (map[new_i][1])
				new_i = map[new_i][1];
			if (map[new_i][0] == 0 || map[new_i][0] > map[crr][0] + 1)
			{
				// cout << "new_i:" << new_i << '\n';
				map[new_i][0] = map[crr][0] + 1;
				q.push(new_i);

				if (new_i == 100)
				{
					cout << map[100][0] << '\n';
					return (0);
				}
			}
		}
	}
}