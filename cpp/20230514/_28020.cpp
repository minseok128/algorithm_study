#include <iostream>
#include <vector>
using namespace std;

int N;
vector<long long> arr1, arr2, tree;

unsigned long long query(int s, int e, int l, int r, int node)
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
		return;
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

	cin >> N;
	arr1.resize(N);
	arr2.resize(N);
	tree.resize(N * 4);
	for (int i = 0; i < N; i++)
		cin >> arr1[i];
	for (int i = 0, tmp; i < N; i++)
	{
		cin >> tmp;
		arr2[tmp] = i;
	}

	unsigned long long tmp, res = 0;
	for (int i = 0; i < N; i++)
	{
		tmp = query(0, N - 1, 0, arr2[arr1[i]], 1);
		// cout << (tmp * (tmp - 1)) / 2 << '\n';
		tmp = (tmp * (tmp - 1)) / 2;
		if (tmp > 3)
			tmp -= 3;
		res += tmp;
		update(0, N - 1, arr2[arr1[i]], 1, 1);
	}
	if (res)
		cout << "My heart has gone to paradise\n"
			 << res << '\n';
	else
		cout << "Attention is what I want\n";
}