#include <iostream>
#include <vector>
using namespace std;

int N;
vector<long long> arr1, arr2, l_tree, r_tree, l_res, r_res;

long long l_query(int s, int e, int l, int r, int node)
{
	if (s > r || e < l)
		return (0);
	if (s >= l && e <= r)
		return (l_tree[node]);
	int m = (s + e) / 2;
	return (l_query(s, m, l, r, node * 2) + l_query(m + 1, e, l, r, node * 2 + 1));
}

void l_update(int s, int e, int t, int v, int node)
{
	if (s == e)
	{
		l_tree[node] = v;
		return;
	}
	int m = (s + e) / 2;
	if (s <= t && t <= m)
		l_update(s, m, t, v, node * 2);
	if (m + 1 <= t && t <= e)
		l_update(m + 1, e, t, v, node * 2 + 1);
	l_tree[node] = l_tree[node * 2] + l_tree[node * 2 + 1];
}

long long r_query(int s, int e, int l, int r, int node)
{
	if (s > r || e < l)
		return (0);
	if (s >= l && e <= r)
		return (r_tree[node]);
	int m = (s + e) / 2;
	return (r_query(s, m, l, r, node * 2) + r_query(m + 1, e, l, r, node * 2 + 1));
}

void r_update(int s, int e, int t, int v, int node)
{
	if (s == e)
	{
		r_tree[node] = v;
		return;
	}
	int m = (s + e) / 2;
	if (s <= t && t <= m)
		r_update(s, m, t, v, node * 2);
	if (m + 1 <= t && t <= e)
		r_update(m + 1, e, t, v, node * 2 + 1);
	r_tree[node] = r_tree[node * 2] + r_tree[node * 2 + 1];
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	cin >> N;
	arr1.resize(N);
	arr2.resize(N);
	l_tree.resize(N * 4);
	r_tree.resize(N * 4);
	l_res.resize(N);
	r_res.resize(N);
	for (int i = 0; i < N; i++)
		cin >> arr1[i];
	for (int i = 0, tmp; i < N; i++)
	{
		cin >> tmp;
		arr2[tmp] = i;
	}

	long long tmp, res = 0;
	for (int i = 0; i < N; i++)
	{
		l_res[i] = l_query(0, N - 1, 0, arr2[arr1[i]], 1);
		l_update(0, N - 1, arr2[arr1[i]], 1, 1);
	}
	for (int i = N - 1; i >= 0; i--)
	{
		r_res[i] = r_query(0, N - 1, arr2[arr1[i]], N - 1, 1);
		r_update(0, N - 1, arr2[arr1[i]], 1, 1);
	}
	for (int i = 0; i < N; i++)
		res += l_res[i] * r_res[i];
	if (res)
		cout << "My heart has gone to paradise\n"
			 << res << '\n';
	else
		cout << "Attention is what I want\n";
}