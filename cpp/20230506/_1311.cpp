#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int n;
	cin >> n;
	vector<vector<int>> dp(n, vector<int>(1 << 20));
	vector<vector<short>> cost(n, vector<short>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> cost[i][j];
	for (int i = 0; i < n; i++)
		dp[0][1 << i] = cost[0][i];

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < 1 << n; k++)
			{
				if (dp[i - 1][k] && !(k & (1 << j)))
				{
					if (dp[i][k | (1 << j)])
						dp[i][k | (1 << j)] = min(dp[i][k | (1 << j)], dp[i - 1][k] + cost[i][j]);
					else
						dp[i][k | (1 << j)] = dp[i - 1][k] + cost[i][j];
				}
			}
		}
	}
	cout << dp[n - 1][(1 << n) - 1] << '\n';
}