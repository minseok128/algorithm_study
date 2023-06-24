#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int> P;

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int n, m;
	cin >> n >> m;

	vector<vector<P>> adj(n);
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		adj[a - 1].push_back({c, b - 1});
		adj[b - 1].push_back({c, a - 1});
	}

	vector<bool> visited(n, false);
	priority_queue<P, vector<P>, greater<P>> pq;

	for(auto &e: adj[0])
		pq.push(e);

	visited[0] = true;
	long long res = 0;
	while(!pq.empty())
	{
		int w = pq.top().first;
		int v = pq.top().second;
		pq.pop();
		if(!visited[v])
		{
			visited[v] = true;
			res += w;
			for(auto &e: adj[v])
				if(!visited[e.second])
					pq.push(e);
		}
	}

	cout << res << '\n';
}