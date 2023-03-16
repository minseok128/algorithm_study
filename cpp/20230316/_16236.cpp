#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> map;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.first < b.first)
		return (true);
	if (a.first == b.first && a.second < b.second)
		return (true);
	return (false);
}

int next_move(int N, int *y, int *x, int *exp, int *size, int *total)
{
	vector<vector<bool>> is_chacked(N, vector<bool>(N, false));
	int dy = 0, dx = 0, count = 0;
	queue<pair<int, pair<int, int>>> q;
	int ans_num = 0;
	vector<pair<int, int>> ans;

	q.push(make_pair(*y, make_pair(*x, 0)));
	while (!q.empty())
	{
		pair<int, pair<int, int>> crr = q.front();
		q.pop();
		if (!is_chacked[crr.first][crr.second.first] && map[crr.first][crr.second.first] <= *size)
		{
			is_chacked[crr.first][crr.second.first] = true;
			if (map[crr.first][crr.second.first] > 0 && map[crr.first][crr.second.first] < *size)
			{
				if (ans_num == 0)
					ans_num = crr.second.second;
				if (ans_num == crr.second.second)
					ans.push_back(make_pair(crr.first, crr.second.first));
				else
					break;
			}
			for (int i = 0; i < 4; i++)
			{
				dy = i == 0 ? -1 : (i == 3 ? 1 : 0);
				dx = i == 1 ? -1 : (i == 2 ? 1 : 0);
				if (crr.first + dy >= 0 && crr.first + dy < N && crr.second.first + dx >= 0 && crr.second.first + dx < N)
					q.push(make_pair(crr.first + dy, make_pair(crr.second.first + dx, crr.second.second + 1)));
			}
		}
	}
	sort(ans.begin(), ans.end(), cmp);
	if (ans_num)
	{
		map[ans[0].first][ans[0].second] = 0;
		*y = ans[0].first;
		*x = ans[0].second;
		(*exp)++;
		if (*exp == *size)
		{
			*size += 1;
			*exp = 0;
		}
		*total += ans_num;
		return (1);
	}
	return (0);
}

int main(void)
{
	int N, y, x, size = 2, exp = 0, total = 0;
	cin >> N;
	map = vector<vector<int>>(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 9)
			{
				map[i][j] = 0;
				y = i;
				x = j;
			}
		}
	}
	while (next_move(N, &y, &x, &exp, &size, &total))
		;
	cout << total << '\n';
}
