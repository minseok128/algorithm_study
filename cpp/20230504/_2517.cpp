#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> tmp0, tmp1, arr, tree;

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

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	cin >> N;
	tmp0.resize(N);
	tmp1.resize(N);
	arr.resize(N);
	tree.resize(N * 4);
	for (int i = 0; i < N; i++)
	{
		cin >> tmp0[i];
		tmp1[i] = i;
	}
	sort(tmp1.begin(), tmp1.end(), [](int a, int b)
		 { return (tmp0[a] < tmp0[b]); });
	for (int i = 1; i < N; i++)
		arr[tmp1[i]] = arr[tmp1[i - 1]] + 1;
	// for (int i = 0; i < N; i++)
	// 	cout << arr[i] << ' ';

	for (int i = 0; i < N; i++)
	{
		cout << i + 1 - query(0, N - 1, 0, arr[i], 1) << '\n';
		update(0, N - 1, arr[i], 1, 1);
	}
}