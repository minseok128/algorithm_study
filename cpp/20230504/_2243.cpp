#include <iostream>
#include <vector>
using namespace std;

const int n = 1'000'000;
vector<int> tree(n * 4, 0);

void update(int s, int e, int t, int v, int node)
{
	if (s == e)
	{
		tree[node] += v;
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

int find(int t)
{
	int s = 0, e = n - 1, m, q;
	while (s <= e)
	{
		m = (s + e) / 2;
		q = query(0, n - 1, 0, m, 1);
		if (q < t)
			s = m + 1;
		else
			e = m - 1;
	}
	return (s);
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int K, a, b, c, d;
	for (cin >> K; K > 0; K--)
	{
		cin >> a >> b;
		if (a == 1)
		{
			d = find(b);
			cout << d + 1 << '\n';
			update(0, n - 1, d, -1, 1);
		}
		else
		{
			cin >> c;
			update(0, n - 1, b - 1, c, 1);
		}
	}
}