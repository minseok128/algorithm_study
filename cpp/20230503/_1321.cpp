#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> arr;
vector<long long> tree;

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
		tree[node] += v;
		return ;
	}
	int m = (s + e) / 2;
	if (s <= t && t <= m)
		update(s, m, t, v, node * 2);
	else if (m + 1 <= t && t <= e)
		update(m + 1, e, t, v, node * 2 + 1);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int find(int t)
{
	int s = 0, e = N - 1, m = (s + e) / 2, mq;
	while (s <= e)
	{
		m = (s + e) / 2;
		mq = query(0, N - 1, 0, m, 1);
		if (mq < t)
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

	cin >> N;
	arr.resize(N);
	tree.resize(N * 4);
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	build(0, N - 1, 1);

	cin >> M;

	int a, b, c;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		if (a == 1)
		{
			cin >> c;
			update(0, N - 1, b - 1, c, 1);
			// for (int i = 0; i < N * 4; i++)
			// 	cout << i << ":" << tree[i] << ' ';
			// cout << '\n';
		}
		else
			cout << find(b) + 1 << '\n';
	}
}