#include <iostream>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int s, e;
		vector<vector<int>> visited(10000, vector<int>(2, 0));
		cin >> s >> e;

		queue<int> q;
		q.push(s);
		visited[s][0] = 1;
		visited[s][1] = 0;
		while (!q.empty())
		{
			int crr = q.front();
			q.pop();
			if (crr == e)
			{
				cout << "find\n";
				stack<int> ptr_s;
				int tmp = e;
				while (1)
				{
					ptr_s.push(visited[tmp][1]);
					tmp = visited[tmp][1];
					if (tmp == 0)
						break;
				}
				while (!ptr_s.empty())
				{
					int crr = ptr_s.top();
					ptr_s.pop();
					char c = crr == 0 ? 'D' : crr == 1 ? 'S'
										  : crr == 2   ? 'L'
													   : 'R';
					cout << c;
				}
				cout << '\n';
				break;
			}

			for (int i = 0; i < 4; i++)
			{
				int new_num;
				if (i == 0)
					new_num = crr * 2 % 10000;
				else if (i == 1)
					new_num = crr - 1 ? crr - 1 : 9999;
				else if (i == 2)
					new_num = ((crr * 10) % 10000) + (crr / 1000);
				else if (i == 3)
					new_num = (crr / 10) + ((crr % 10) * 1000);
				if (visited[new_num][0] == 0)
				{
					cout << new_num << '\n';
					visited[new_num][0] = crr;
					visited[new_num][1] = i;
					q.push(new_num);
				}
			}
		}
	}
}