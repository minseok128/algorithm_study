#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> tmp, arr, tree;

void update(int s, int e, int t, int v, int node)
{
	if (s == e)
	{
		tree[node] = v;
		return;
	}
	int m = (s + e) / 2;
	if (s <= t && t <= m)
		update(s, m, t, v, node * 2);
	if (m + 1 <= t && t <= e)
		update(m + 1, e, t, v, node * 2 + 1);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(int s, int e, int l, int r, int node)
{
	if (s > r || e < l)
		return (0);
	if (s >= l && e <= r)
		return (tree[node]);
	int m = (s + e) / 2;
	return (query(s, m, l, r, node * 2) + query(m + 1, e, l, r, node * 2 + 1));
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	cin >> N;
	tmp.resize(N);
	arr.resize(N);
	tree.resize(N * 4);
	for (int i = N - 1; i >= 0; i--)
	{
		cin >> tmp[i];
		arr[i] = i;
	}
	sort(arr.begin(), arr.end(), [](int a, int b)
		 { if (tmp[a] == tmp[b]) return (a > b); return (tmp[a] < tmp[b]); });
	long long res = 0;
	for (int i = 0; i < N; i++)
	{
		if (arr[i] != 0)
			res += query(0, N - 1, 0, arr[i], 1);
		update(0, N - 1, arr[i], 1, 1);
	}
	cout << res << '\n';
}