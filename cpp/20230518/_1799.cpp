#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef struct
{
	int valid, y, x;
} Node;

int N, max_n, result = 0;
vector<vector<Node>> map;
vector<int> rcross;

void recursive(int n, int cnt)
{
	if (max_n - n + 1 + cnt < result)
		return;
	if (n == max_n)
	{
		result = max(cnt, result);
		if (result == max_n - 1)
		{
			cout << result << '\n';
			exit(0);
		}
		return;
	}
	for (int i = 0; i < map[n].size(); i++)
	{
		Node crr = map[n][i];
		if (crr.valid && !rcross[crr.x + crr.y])
		{
			rcross[crr.x + crr.y] = 1;
			recursive(n + 1, cnt + 1);
			rcross[crr.x + crr.y] = 0;
		}
	}
	recursive(n + 1, cnt);
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	cin >> N;
	max_n = N * 2 - 1;
	map.resize(max_n);
	rcross.resize(max_n);

	int tmp;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> tmp;
			map[N - 1 - i + j].emplace_back(Node{tmp, i, j});
		}
	recursive(0, 0);
	cout << result << '\n';
}