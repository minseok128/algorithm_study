#include <iostream>
#include <vector>
using namespace std;

int N, Q;
vector<long long> arr, tree;

long long build(int s, int e, int node)
{
	if (s == e)
		tree[node] = arr[s];
	else
	{
		int m = (s + e) / 2;
		tree[node] = build(s, m, node * 2) + build(m + 1, e, node * 2 + 1);
	}
	return (tree[node]);
}

long long query(int s, int e, int l, int r, int node)
{
	if (s > r || e < l)
		return (0);
	if (s >= l && e <= r)
		return (tree[node]);
	int m = (s + e) / 2;
	return (query(s, m, l, r, node * 2) + query(m + 1, e, l, r, node * 2 + 1));
}

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

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	cin >> N >> Q;
	arr = vector<long long>(N);
	tree = vector<long long>(N * 4);
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	build(0, N - 1, 1);

	int x, y, a, b;
	for (int i = 0; i < Q; i++)
	{
		cin >> x >> y >> a >> b;
		if (x > y)
		{
			int tmp = x;
			x = y;
			y = tmp;
		}
		cout << query(0, N - 1, x - 1, y - 1, 1) << '\n';
		update(0, N - 1, a - 1, b, 1);
	}
}