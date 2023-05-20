#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int N, K, result = -1;
int subin[500'001];
int subin_check[500'001];
int check[500'001][2];

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
		int crr_x = q.front().first, crr_t = q.front().second;
		q.pop();

		for (int i = 0; i < 3; i++)
		{
			int new_x = i ? (i == 1 ? crr_x + 1 : crr_x * 2) : crr_x - 1, new_t = crr_t + 1;
			if (new_x >= 0 && new_x <= 500'000 && !check[new_x][new_t % 2])
			{
				if (subin[new_x] >= new_t && subin[new_x] % 2 == new_t % 2)
					result = result == -1 ? subin[new_x] : min(subin[new_x], result);
				check[new_x][new_t % 2] = 1;
				q.push({new_x, new_t});
			}
		}
	}
	cout << result << '\n';
}