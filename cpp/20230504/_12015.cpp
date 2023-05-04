#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int N;
vector<int> tmp1, arr, tree;

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
	tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
}

int query(int s, int e, int l, int r, int node)
{
	if (s > r || e < l)
		return (-1);
	if (s >= l && e <= r)
		return (tree[node]);
	int m = (s + e) / 2;
	return (max(query(s, m, l, r, node * 2), query(m + 1, e, l, r, node * 2 + 1)));
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	cin >> N;
	tmp1.resize(N);
	arr.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> tmp1[i];
		arr[i] = i;
	}
	sort(arr.begin(), arr.end(), [](int a, int b)
		 { if(tmp1[a] == tmp1[b]) return(a > b);
			return (tmp1[a] < tmp1[b]); });
	// for (int i = 0; i < N; i++)
	// 	cout << arr[i] << ' ';
	// cout << '\n';

	int q, res = 1;
	tree.resize(N * 4);
	for (int i = 0; i < N; i++)
	{
		if (arr[i] != 0)
		{
			q = query(0, N - 1, 0, arr[i] - 1, 1) + 1;
			// cout << "i:" << i << " q:" << q << '\n';
			res = max(q, res);
		}
		else
			q = 1;
		update(0, N - 1, arr[i], q, 1);
	}
	cout << res << '\n';
}