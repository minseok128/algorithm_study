#include <iostream>
#include <vector>
using namespace std;

typedef struct
{
	int val, idx;
} Node;

int N, M;
vector<Node> arr, tree;

Node max(Node a, Node b)
{
	return (a.val > b.val ? a : b);
}

Node build(int s, int e, int node)
{
	if (s == e)
		tree[node] = arr[s];
	else
	{
		int m = (s + e) / 2;
		tree[node] = max(build(s, m, node * 2), build(m + 1, e, node * 2 + 1));
	}
	return (tree[node]);
}

Node query(int s, int e, int l, int r, int node)
{
	if (s > r || e < l)
		return (Node{0, 0});
	if (s >= l && e <= r)
		return (tree[node]);
	int m = (s + e) / 2;
	return (max(query(s, m, l, r, node * 2), query(m + 1, e, l, r, node * 2 + 1)));
}

void update(int s, int e, int t, int v, int node)
{
	if (s == e)
	{
		tree[node].val = v;
		return;
	}
	int m = (s + e) / 2;
	if (s <= t && t <= m)
		update(s, m, t, v, node * 2);
	if (m + 1 <= t && t <= e)
		update(m + 1, e, t, v, node * 2 + 1);
	tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	cin >> N;
	arr.resize(N);
	tree.resize(N * 4);
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i].val;
		arr[i].idx = i;
	}
	build(0, N - 1, 1);

	int a, b, c;
	Node tmp, tmp2;
	for (cin >> M; M > 0; M--)
	{
		cin >> a >> b >> c;
		if (a == 1)
		{
			update(0, N - 1, b - 1, c, 1);
		}
		else
		{
			tmp = query(0, N - 1, b - 1, c - 1, 1);
			if (tmp.idx == b - 1)
				tmp2 = query(0, N - 1, tmp.idx + 1, c - 1, 1);
			if (tmp.idx == c - 1)
				tmp2 = query(0, N - 1, b - 1, tmp.idx - 1, 1);
			else
				tmp2 = max(query(0, N - 1, tmp.idx + 1, c - 1, 1), query(0, N - 1, b - 1, tmp.idx - 1, 1));
			cout << tmp.val + tmp2.val << '\n';
		}
	}
}