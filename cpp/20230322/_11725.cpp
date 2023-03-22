#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	cin >> N;
	vector<vector<int>> tree(N + 1, vector<int>());
	vector<int> result(N + 1, 0);
	for (int i = 0; i < N - 1; i++)
	{
		int p1, p2;
		cin >> p1 >> p2;
		tree[p1].push_back(p2);
		tree[p2].push_back(p1);
	}
	
	queue<int> q;
	q.push(1);
	result[1] = -1;
	while (!q.empty())
	{
		int crr = q.front();
		q.pop();

		for (int i = 0; i < tree[crr].size(); i++)
		{
			if (result[tree[crr][i]] == 0)
			{
				result[tree[crr][i]] = crr;
				q.push(tree[crr][i]);
			}
		}
	}
	for (int i = 2; i <= N; i++)
		cout << result[i] << '\n';
}