#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int T, N;
vector<int> arr, tree, info;

int max_build(int s, int e, int node)
{
	if (s == e)
		tree[node] = arr[s];
	else
	{
		int m = (s + e) / 2;
		tree[node] = max(max_build(s, m, node * 2), max_build(m + 1, e, node * 2 + 1));
	}
	return (tree[node]);
}

int max_query(int s, int e, int l, int r, int node)
{
	if (s > r || e < l)
		return (0);
	if (s >= l && e <= r)
		return (tree[node]);
	int m = (s + e) / 2;
	return (max(max_query(s, m, l, r, node * 2), max_query(m + 1, e, l, r, node * 2 + 1)));
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	for (cin >> T; T > 0; T--)
	{
		cin >> N;
		tree.clear();
		info.clear();
		arr.resize(N + 1);
		info.resize(N + 1);
		tree.resize((N + 1) * 4);

		for (int i = 1; i <= N; i++)
			cin >> arr[i];
		max_build(0, N, 1);

		int flag = 0;
		for (int i = 1; i <= N && !flag; i++)
		{
			if (!info[arr[i]])
				info[arr[i]] = i;
			else
			{
				//cout << i << "," << info[i] << max_query(0, N, info[i], i, 1) << '\n';
				if (max_query(0, N, info[arr[i]], i, 1) > arr[i])
				{
					flag = 1;
				}
				info[arr[i]] = i;
			}
		}
		cout << (flag ? "No\n" : "Yes\n");
	}
}