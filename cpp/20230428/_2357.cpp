#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N, M;
vector<int> arr, min_tree, max_tree;

int min_build(int s, int e, int node)
{
	if (s == e)
		min_tree[node] = arr[s];
	else
	{
		int m = (s + e) / 2;
		min_tree[node] = min(min_build(s, m, node * 2), min_build(m + 1, e, node * 2 + 1));
	}
	return (min_tree[node]);
}

int min_query(int s, int e, int l, int r, int node)
{
	if (s > r || e < l)
		return (1000000001);
	if (s >= l && e <= r)
		return (min_tree[node]);
	int m = (s + e) / 2;
	return (min(min_query(s, m, l, r, node * 2), min_query(m + 1, e, l, r, node * 2 + 1)));
}

int max_build(int s, int e, int node)
{
	if (s == e)
		max_tree[node] = arr[s];
	else
	{
		int m = (s + e) / 2;
		max_tree[node] = max(max_build(s, m, node * 2), max_build(m + 1, e, node * 2 + 1));
	}
	return (max_tree[node]);
}

int max_query(int s, int e, int l, int r, int node)
{
	if (s > r || e < l)
		return (0);
	if (s >= l && e <= r)
		return (max_tree[node]);
	int m = (s + e) / 2;
	return (max(max_query(s, m, l, r, node * 2), max_query(m + 1, e, l, r, node * 2 + 1)));
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	cin >> N >> M;
	arr = vector<int>(N);
	min_tree = vector<int>(N * 4);
	max_tree = vector<int>(N * 4);
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	min_build(0, N - 1, 1);
	max_build(0, N - 1, 1);
	for (int i = 0; i < M; i++)
	{
		int l, r;
		cin >> l >> r;
		cout << min_query(0, N - 1, l - 1, r - 1, 1) << ' ' << max_query(0, N - 1, l - 1, r - 1, 1) << '\n';
	}
}