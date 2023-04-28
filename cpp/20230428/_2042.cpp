#include <iostream>
#include <vector>
using namespace std;

int N, M, K;
vector<long long> arr;
vector<long long> tree;

long long build(int s, int e, int node)
{
	if (s == e)
		tree[node] = arr[s];
	else
	{
		int mid = (s + e) / 2;
		tree[node] = build(s, mid, node * 2) + build(mid + 1, e, node * 2 + 1);
	}
	return (tree[node]);
}

long long query(int s, int e, int l, int r, int node)
{
	if (s > r || e < l)
		return (0);
	if (s >= l && e <= r)
		return (tree[node]);
	int mid = (s + e) / 2;
	return (query(s, mid, l, r, node * 2) + query(mid + 1, e, l, r, node * 2 + 1));
}

void update(int s, int e, int t, long long val, int node)
{
	if (s == e)
	{
		tree[node] = val;
		return;
	}
	int m = (s + e) / 2;
	if (s <= t && t <= m)
		update(s, m, t, val, node * 2);
	if (m + 1 <= t && t <= e)
		update(m + 1, e, t, val, node * 2 + 1);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	cin >> N >> M >> K;
	arr = vector<long long>(N + 1);
	tree = vector<long long>(4 * N);
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	build(0, N - 1, 1);
	for (int i = 0; i < M + K; i++)
	{
		long long a, b, c;
		cin >> a >> b >> c;
		if (a == 1)
			update(0, N - 1, b - 1, c, 1);
		else
			cout << query(0, N - 1, b - 1, c - 1, 1) << '\n';
	}
}