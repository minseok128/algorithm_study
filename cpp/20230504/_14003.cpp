#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int N;
vector<int> tmp1, arr;
vector<pair<int, int>> tree;

void update(int s, int e, int t, pair<int, int> v, int node)
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

pair<int, int> query(int s, int e, int l, int r, int node)
{
	if (s > r || e < l)
		return (make_pair(0, 0));
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

	int prev = 0;
	pair<int, int> q, res = {0, 0};
	tree.resize(N * 4);
	vector<int> d(N);
	for (int i = 0; i < N; i++)
	{
		if (arr[i] != 0)
		{
			q = query(0, N - 1, 0, arr[i] - 1, 1);
			q.first++;
		}
		else
			q.first = 1;
		if (q.first > res.first)
			res = {q.first, arr[i]};
		d[arr[i]] = q.second;
		update(0, N - 1, arr[i], make_pair(q.first, arr[i]), 1);
	}
	cout << res.first << '\n';

	int next = res.second;
	vector<int> real(res.first);
	for (int i = 0; i < res.first; i++)
	{
		real[i] = next;
		next = d[next];
	}
	for (int i = res.first - 1; i >= 0; i--)
		cout << tmp1[real[i]] << ' ';
}