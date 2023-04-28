#include <iostream>
#include <vector>
using namespace std;

int N, M, K;
const int mod = 1000000007;
vector<long long> arr, tree;

long long build(int s, int e, int node)
{
	if (s == e)
		tree[node] = arr[s] % mod;
	else
	{
		int m = (s + e) / 2;
		tree[node] = (build(s, m, node * 2) * build(m + 1, e, node * 2 + 1)) % mod;
	}
	return (tree[node]);
}

long long query(int s, int e, int l, int r, int node)
{
	if (s > r || e < l)
		return (1);
	if (s >= l && e <= r)
		return (tree[node]);
	int m = (s + e) / 2;
	return ((query(s, m, l, r, node * 2) * query(m + 1, e, l, r, node * 2 + 1)) % mod);
}

void update(int s, int e, int t, long long val, int node)
{
	if (s == e)
	{
		tree[node] = val % mod;
		return;
	}
	int m = (s + e) / 2;
	if (s <= t && t <= m)
		update(s, m, t, val, node * 2);
	if (m + 1 <= t && t <= e)
		update(m + 1, e, t, val, node * 2 + 1);
	tree[node] = (tree[node * 2] * tree[node * 2 + 1]) % mod;
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	cin >> N >> M >> K;
	arr = vector<long long>(N);
	tree = vector<long long>(N * 4);
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