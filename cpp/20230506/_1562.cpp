#include <iostream>
#include <vector>
using namespace std;

const int mod = 1'000'000'000;

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int n;
	cin >> n;
	vector<vector<vector<int>>> dp(n, vector<vector<int>>(10, vector<int>(1024, 0)));
	for (int i = 1; i < 10; i++)
		dp[0][i][1 << i] = 1;
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j != 0)
				for (int k = 0; k < 1024; k++)
					dp[i][j][k | (1 << j)] += dp[i - 1][j - 1][k] % mod;
			if (j != 9)
				for (int k = 0; k < 1024; k++)
					dp[i][j][k | (1 << j)] += dp[i - 1][j + 1][k] % mod;
		}
	}
	long long res = 0;
	for (int j = 0; j < 10; j++)
		res = (res + dp[n - 1][j][1023]) % mod;
	cout << res << '\n';
}