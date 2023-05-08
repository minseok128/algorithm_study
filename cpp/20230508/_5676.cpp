#include <iostream>
#include <vector>
using namespace std;

int N, K;
vector<int> arr;
vector<int> tree;

int build(int s, int e, int node)
{
	if (s == e)
	{
		if (arr[s] > 0)
			tree[node] = 1;
		else if (arr[s] < 0)
			tree[node] = -1;
		else
			tree[node] = 0;
	}
	else
	{
		int m = (s + e) / 2;
		tree[node] = build(s, m, node * 2) * build(m + 1, e, node * 2 + 1);
	}
	return (tree[node]);
}

int query(int s, int e, int l, int r, int node)
{
	if (s > r || e < l)
		return (1);
	if (s >= l && e <= r)
		return (tree[node]);
	int m = (s + e) / 2;
	return (query(s, m, l, r, node * 2) * query(m + 1, e, l, r, node * 2 + 1));
}

void update(int s, int e, int t, int v, int node)
{
	if (s == e)
	{
		if (v > 0)
			tree[node] = 1;
		else if (v < 0)
			tree[node] = -1;
		else
			tree[node] = 0;
		return;
	}
	int m = (s + e) / 2;
	if (s <= t && t <= m)
		update(s, m, t, v, node * 2);
	else if (m + 1 <= t && t <= e)
		update(m + 1, e, t, v, node * 2 + 1);
	tree[node] = tree[node * 2] * tree[node * 2 + 1];
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	char a;
	int b, c, q;
	while (cin >> N >> K)
	{
		arr.clear();
		arr.resize(N);
		tree.clear();
		tree.resize(N * 4);
		for (int i = 0; i < N; i++)
			cin >> arr[i];
		build(0, N - 1, 1);
		for (int i = 0; i < K; i++)
		{
			cin >> a >> b >> c;
			if (a == 'C')
				update(0, N - 1, b - 1, c, 1);
			else
			{
				q = query(0, N - 1, b - 1, c - 1, 1);
				cout << (q == 1 ? '+' : q == -1 ? '-'
												: '0');
			}
		}
		cout << '\n';
	}
};