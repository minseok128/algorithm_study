#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N, M;
vector<int> arr, tree;

int build(int s, int e, int node)
{
	if (s == e)
		tree[node] = arr[s];
	else
	{
		int m = (s + e) / 2;
		tree[node] = min(build(s, m, node * 2), build(m + 1, e, node * 2 + 1));
	}
	return (tree[node]);
}

int query(int s, int e, int l, int r, int node)
{
	if (s > r || e < l)
		return (1000000001);
	if (s >= l && e <= r)
		return (tree[node]);
	int m = (s + e) / 2;
	return (min(query(s, m, l, r, node * 2), query(m + 1, e, l, r, node * 2 + 1)));
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	cin >> N >> M;
	arr = vector<int>(N);
	tree = vector<int>(N * 4);
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	build(0, N - 1, 1);
	for (int i = 0; i < M; i++)
	{
		int l, r;
		cin >> l >> r;
		cout << query(0, N - 1, l - 1, r - 1, 1) << '\n';
	}
}