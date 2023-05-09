#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> arr;
vector<int> pos;
vector<int> tree;

int build(int s, int e, int node)
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

int query(int s, int e, int l, int r, int node)
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
		return ;
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

	int T, a;
	for (cin >> T; T > 0; T--)
	{
		cin >> N >> M;
		tree.clear();
		arr.clear();

		arr.resize(N + M, 0);
		pos.resize(N);
		for (int i = 0; i < N; i++)
		{
			pos[i] = M + i;
			arr[M + i] = 1;
		}

		tree.resize((N + M) * 4);
		build(0, N + M - 1, 1);
		for (int tmpM = M - 1; tmpM >= 0; tmpM--)
		{
			cin >> a;
			cout << query(0, N + M - 1, 0, pos[a - 1] - 1, 1) << ' ';
			update(0, N + M - 1, pos[a - 1], 0, 1);
			pos[a - 1] = tmpM;
			update(0, N + M - 1, pos[a - 1], 1, 1);
		}
		cout << '\n';
	}
}