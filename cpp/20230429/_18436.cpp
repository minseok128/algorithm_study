#include <iostream>
#include <vector>
using namespace std;

int N, Q;
vector<pair<int, int>> tree;

void build()
{
	for (int i = N - 1; i > 0; i--)
	{
		tree[i].first = tree[i * 2].first + tree[i * 2 + 1].first;
		tree[i].second = tree[i * 2].second + tree[i * 2 + 1].second;
	}
}

pair<int, int> query(int l, int r)
{
	l += N;
	r += N;
	pair<int, int> res = {0, 0};
	while (l < r)
	{
		if (l & 1)
		{
			res.first += tree[l].first;
			res.second += tree[l].second;
			l++;
		}
		if (r & 1)
		{
			r--;
			res.first += tree[r].first;
			res.second += tree[r].second;
		}
		l >>= 1;
		r >>= 1;
	}
	return (res);
}

void update(int t, int v)
{
	t += N;
	if (v & 1)
	{
		tree[t].first = 1;
		tree[t].second = 0;
	}
	else
	{
		tree[t].first = 0;
		tree[t].second = 1;
	}
	while (t > 1)
	{
		tree[t >> 1].first = tree[t].first + tree[t ^ 1].first;
		tree[t >> 1].second = tree[t].second + tree[t ^ 1].second;
		t >>= 1;
	}
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	cin >> N;
	tree = vector<pair<int, int>>(N * 2);
	int tmp;
	for (int i = N; i < N * 2; i++)
	{
		cin >> tmp;
		if (tmp & 1)
		{
			tree[i].first = 1;
			tree[i].second = 0;
		}
		else
		{
			tree[i].first = 0;
			tree[i].second = 1;
		}
	}
	build();
	// for (int i = 0; i < N * 2; i++)
	//	cout << i << "i:" << tree[i].first << ' ' << tree[i].second << ' ';

	cin >> Q;
	int a, b, c;
	for (int i = 0; i < Q; i++)
	{
		cin >> a >> b >> c;
		if (a == 1)
			update(b - 1, c);
		else if (a == 2)
			cout << query(b - 1, c).second << '\n';
		else
			cout << query(b - 1, c).first << '\n';
	}
}
