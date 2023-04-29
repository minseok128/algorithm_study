#include <iostream>
#include <vector>
using namespace std;

int N, Q;
vector<long long> tree;

void build()
{
	for (int i = N - 1; i > 0; i--)
		tree[i] = tree[i * 2] + tree[i * 2 + 1];
}

long long query(int l, int r)
{
	l += N;
	r += N;
	long long res = 0;
	while (l < r)
	{
		if (l & 1)
			res += tree[l++];
		if (r & 1)
			res += tree[--r];
		l >>= 1;
		r >>= 1;
	}
	return (res);
}

void update(int t, int v)
{
	t += N;
	tree[t] += v;
	while (t > 1)
	{
		tree[t >> 1] = tree[t] + tree[t ^ 1];
		t >>= 1;
	}
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	cin >> N >> Q;
	tree = vector<long long>(N * 2, 0);

	int a, b, c;
	for (int i = 0; i < Q; i++)
	{
		cin >> a >> b >> c;
		if (a == 1)
			update(b - 1, c);
		else
			cout << query(b - 1, c) << '\n';
	}
}
