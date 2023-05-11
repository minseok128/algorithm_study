#include <iostream>
#include <vector>
using namespace std;

int T, N, M;
vector<int> arr;
vector<vector<int>> tree;
int (*f[2])(int, int);

int min(int a, int b)
{
	return (a > b ? b : a);
}

int max(int a, int b)
{
	return (a > b ? a : b);
}

int build(int s, int e, int node, int type)
{
	if (s == e)
		tree[type][node] = arr[s];
	else
	{
		int m = (s + e) / 2;
		tree[type][node] = f[type](build(s, m, node * 2, type), build(m + 1, e, node * 2 + 1, type));
	}
	return (tree[type][node]);
}

int query(int s, int e, int l, int r, int node, int type)
{
	if (s > r || e < l)
		return (type ? -1 : 100001);
	if (s >= l && e <= r)
		return (tree[type][node]);
	int m = (s + e) / 2;
	return (f[type](query(s, m, l, r, node * 2, type), query(m + 1, e, l, r, node * 2 + 1, type)));
}

void update(int s, int e, int t, int v, int node, int type)
{
	if (s == e)
	{
		tree[type][node] = v;
		return ;
	}
	int m = (s + e) / 2;
	if (s <= t && t <= m)
		update(s, m, t, v, node * 2, type);
	if (m + 1 <= t && t <= e)
		update(m + 1, e, t, v, node * 2 + 1, type);
	tree[type][node] = f[type](tree[type][node * 2], tree[type][node * 2 + 1]);
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int a, b, c;
	f[0] = &min;
	f[1] = &max;
	for (cin >> T; T > 0; T--)
	{
		arr.clear();
		tree.clear();
		cin >> N >> M;
		arr.resize(N);
		tree = vector<vector<int>>(2, vector<int>(N * 4));
		for (int i = 0; i < N; i++)
			arr[i] = i;
		build(0, N - 1, 1, 0);
		build(0, N - 1, 1, 1);

		for (int i = 0; i < M; i++)
		{
			cin >> a >> b >> c;
			if (a)
			{
				if (c == query(0, N - 1, b, c, 1, 1) && b == query(0, N - 1, b, c, 1, 0))
					cout << "YES\n";
				else
					cout << "NO\n";
			}
			else
			{
				int tmpb = query(0, N - 1, b, b, 1, 0);
				int tmpc = query(0, N - 1, c, c, 1, 0);
				update(0, N - 1, b, tmpc, 1, 0);
				update(0, N - 1, c, tmpb, 1, 0);
				update(0, N - 1, b, tmpc, 1, 1);
				update(0, N - 1, c, tmpb, 1, 1);
			}
		}
	}
}