#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	for (int t = 1;; t++)
	{
		int n, m, a, b, num = 0, flag, tree = 0;
		cin >> n >> m;
		if (!n && !m)
			return (0);
		vector<pair<int, int>> checked(n);
		vector<vector<int>> nodes(n);
		for (int i = 0; i < m; i++)
		{
			cin >> a >> b;
			nodes[a - 1].emplace_back(b - 1);
			nodes[b - 1].emplace_back(a - 1);
		}

		queue<int> q;
		for (int i = 0; i < n; i++)
		{
			if (checked[i].first == 0)
			{
				flag = 1;
				num++;
				q.push(i);
				checked[i].first = num;
				while (!q.empty())
				{
					int crr = q.front();
					q.pop();
					for (int j = 0; j < nodes[crr].size(); j++)
					{
						int new_i = nodes[crr][j];
						if (checked[new_i].first == 0)
						{
							checked[new_i].first = num;
							checked[new_i].second = crr;
							q.push(new_i);
						}
						else if (new_i != crr && checked[crr].second != new_i)
							flag = 0;
					}
				}
				tree += flag;
			}
		}
		cout << "Case " << t << ": ";
		if (tree == 0)
			cout << "No trees.\n";
		else if (tree == 1)
			cout << "There is one tree.\n";
		else
			cout << "A forest of " << tree << " trees.\n";
	}
}