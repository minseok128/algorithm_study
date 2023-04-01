#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

char DSLR[] = {'D', 'S', 'L', 'R'};

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int T;
	cin >> T;
	int visited[10000][2];
	for (int t = 0; t < T; t++)
	{
		memset(visited, -1, sizeof(visited));
		int s, e, flag = 1;
		cin >> s >> e;

		queue<int> q;
		q.push(s);
		while (!q.empty() && flag)
		{
			int crr = q.front();
			q.pop();
			for (int i = 0; i < 4; i++)
			{
				int new_num;
				if (i == 0)
					new_num = crr * 2 % 10000;
				else if (i == 1)
					new_num = crr ? crr - 1 : 9999;
				else if (i == 2)
					new_num = ((crr * 10) % 10000) + (crr / 1000);
				else if (i == 3)
					new_num = (crr / 10) + ((crr % 10) * 1000);
				if (new_num >= 0 && new_num < 10000 && visited[new_num][0] == -1)
				{
					visited[new_num][0] = crr;
					visited[new_num][1] = i;
					q.push(new_num);
					if (new_num == e)
					{
						string ans;
						int tmp = e;
						while (tmp != s)
						{
							ans += DSLR[visited[tmp][1]];
							tmp = visited[tmp][0];
						}
						for (int i = ans.size() - 1; i >= 0; i--)
							cout << ans[i];
						cout << '\n';
						flag = 0;
						break ;
					}
				}
			}
		}
	}
}
