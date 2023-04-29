#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N, L;
vector<int> tree;

void build()
{
	for (int i = N - 1; i > 0; i--)
		tree[i] = min(tree[i * 2], tree[i * 2 + 1]);
}

long long query(int l, int r)
{
	l += N;
	r += N;
	int res = 2147483647;
	while (l < r)
	{
		if (l & 1)
			res = min(res, tree[l++]);
		if (r & 1)
			res = min(res, tree[--r]);
		l >>= 1;
		r >>= 1;
	}
	return (res);
}

void update(int t, int v)
{
	t += N;
	tree[t] = v;
	while (t > 1)
	{
		tree[t >> 1] = min(tree[t], tree[t ^ 1]);
		t >>= 1;
	}
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	cin >> N >> L;
	tree = vector<int>(N * 2, 2147483647);
	for (int i = N; i < N * 2; i++)
		cin >> tree[i];
	build();
	for (int i = 1; i <= N; i++)
	{
		// cout << i - L << ":" << i << '\n';
		if (i - L < 0)
			cout << query(0, i) << ' ';
		else
			cout << query(i - L, i) << ' ';
	}
}