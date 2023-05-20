#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int N, K, result = -1;
int subin[500'001], check[500'001][2];

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	cin >> N >> K;
	if (N == K)
	{
		cout << "0\n";
		return (0);
	}
	for (int i = 0, tmp = K; tmp <= 500'000; tmp += i)
		subin[tmp] = i++;
	if (subin[N] && subin[N] % 2 == 0)
		result = subin[N];

	queue<pair<int, int>> q;
	q.push({N, 0});
	check[N][0] = 1;
	while (!q.empty())
	{
		int x = q.front().first, t = q.front().second;
		q.pop();

		for (int i = 0; i < 3; i++)
		{
			int nx = i ? (i == 1 ? x + 1 : x * 2) : x - 1, nt = t + 1;
			if (nx >= 0 && nx <= 500'000 && !check[nx][nt % 2])
			{
				if (subin[nx] >= nt && subin[nx] % 2 == nt % 2)
					result = result == -1 ? subin[nx] : min(subin[nx], result);
				check[nx][nt % 2] = 1;
				q.push({nx, nt});
			}
		}
	}
	cout << result << '\n';
}