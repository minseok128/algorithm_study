#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> arr;
vector<pair<long long, int>> tree;

pair<long long, int> build(int s, int e, int node)
{
	if (s == e)
		tree[node] = {arr[s], s + 1};
	else
	{
		int m = (s + e) / 2;
		pair<long long, int> tmp1, tmp2;
		tmp1 = build(s, m, node * 2);
		tmp2 = build(m + 1, e, node * 2 + 1);
		if (tmp1.first > tmp2.first)
			tree[node] = tmp2;
		else
			tree[node] = tmp1;
	}
	return (tree[node]);
}

pair<long long, int> query(int s, int e, int l, int r, int node)
{
	if (s > r || e < l)
		return (make_pair(2147483647, -1));
	if (s >= l && e <= r)
		return (tree[node]);
	int m = (s + e) / 2;

	pair<long long, int> tmp1, tmp2;
	tmp1 = query(s, m, l, r, node * 2);
	tmp2 = query(m + 1, e, l, r, node * 2 + 1);
	if (tmp1.first > tmp2.first)
		return (tmp2);
	else
		return (tmp1);
}

void update(int s, int e, int t, int v, int node)
{
	if (s == e)
	{
		tree[node].first = v;
		return;
	}
	int m = (s + e) / 2;
	if (s <= t && t <= m)
		update(s, m, t, v, node * 2);
	if (m + 1 <= t && t <= e)
		update(m + 1, e, t, v, node * 2 + 1);
	pair<long long, int> tmp1, tmp2;
	tmp1 = tree[node * 2];
	tmp2 = tree[node * 2 + 1];
	if (tmp1.first > tmp2.first)
		tree[node] = tmp2;
	else
		tree[node] = tmp1;
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	cin >> N;
	arr = vector<int>(N);
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	tree = vector<pair<long long, int>>(N * 4);
	build(0, N - 1, 1);

	cin >> M;
	int a, b, c;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b >> c;
		if (a == 2)
			cout << query(0, N - 1, b - 1, c - 1, 1).second << '\n';
		else
			update(0, N - 1, b - 1, c, 1);
	}
}