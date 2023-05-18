#include <iostream>
#include <vector>
using namespace std;

int N, M, K;
vector<long long> arr, tree, lazy;

void build(int s, int e, int node)
{
	if (s == e)
		tree[node] = arr[s];
	else
	{
		int m = (s + e) / 2;
		build(s, m, node * 2);
		build(m + 1, e, node * 2 + 1);
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}
}

void propagate(int s, int e, int node)
{
	if (lazy[node] != 0)
	{
		if (s != e)
		{
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		tree[node] += lazy[node] * (e - s + 1);
		lazy[node] = 0;
	}
}

void range_update(int s, int e, int l, int r, long long v, int node)
{
	propagate(s, e, node);
	if (s > r || e < l)
		return;
	if (s >= l && e <= r)
	{
		lazy[node] += v;
		propagate(s, e, node);
		return;
	}
	int m = (s + e) / 2;
	range_update(s, m, l, r, v, node * 2);
	range_update(m + 1, e, l, r, v, node * 2 + 1);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

long long query(int s, int e, int l, int r, int node)
{
	propagate(s, e, node);
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

	cin >> N >> M >> K;
	arr.resize(N);
	tree.resize(N * 4);
	lazy.resize(N * 4);
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	build(0, N - 1, 1);

	long long a, b, c, d;
	for (int i = 0; i < M + K; i++)
	{
		cin >> a >> b >> c;
		if (a == 1)
		{
			cin >> d;
			range_update(0, N - 1, b - 1, c - 1, d, 1);
		}
		else
			cout << query(0, N - 1, b - 1, c - 1, 1) << '\n';
	}
}