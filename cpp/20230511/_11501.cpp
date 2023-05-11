#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int N, M;
vector<pair<int, int>> arr, tree;

pair<int, int> build(int s, int e, int node)
{
	if (s == e)
		tree[node] = arr[s];
	else
	{
		int m = (s + e) / 2;
		tree[node] = max(build(s, m, node * 2), build(m + 1, e, node * 2 + 1));
	}
	return (tree[node]);
}

pair<int, int> query(int s, int e, int l, int r, int node)
{
	if (s > r || e < l)
		return (make_pair(-1, 0));
	if (s >= l && e <= r)
		return (tree[node]);
	int m = (s + e) / 2;
	return (max(query(s, m, l, r, node * 2), query(m + 1, e, l, r, node * 2 + 1)));
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int T;
	for (cin >> T; T > 0; T--)
	{
		int N;
		cin >> N;
		arr.resize(N);
		tree.resize(N * 4);
		for (int i = 0; i < N; i++)
		{
			cin >> arr[i].first;
			arr[i].second = i;
		}
		build(0, N - 1, 1);

		long long res = 0, start = 0;
		pair<int, int> idx;
		while (start != N)
		{
			idx = query(0, N - 1, start, N - 1, 1);
			for (int i = start; i < idx.second; i++)
				res += idx.first - arr[i].first;
			// cout << "idx:" << idx.second << '\n';
			start = idx.second + 1;
		}
		cout << res << '\n';
	}
}