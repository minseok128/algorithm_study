#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> arr;
vector<long long> tree;

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

	cin >> N >> M;
	arr = vector<int>(N, 0);
	tree = vector<long long>(N * 4, 0);

	int a, b, c;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b >> c;
		if (a)
			update(0, N - 1, b - 1, c, 1);
		else
		{
			if (b > c)
			{
				int tmp = b;
				b = c;
				c = tmp;
			}
			cout << query(0, N - 1, b - 1, c - 1, 1) << '\n';
		}
	}
}