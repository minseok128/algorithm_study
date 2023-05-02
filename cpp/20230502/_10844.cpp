#include <iostream>
#include <vector>
using namespace std;

int N, mod = 1000000000;
vector<vector<int>> dp;

int main()
{
	cin >> N;
	dp = vector<vector<int>>(N, vector<int>(10, 1));
	dp[0][0] = 0;
	for (int i = 1; i < N; i++)
	{
		dp[i][0] = dp[i - 1][1] % mod;
		for (int j = 1; j < 9; j++)
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % mod;
		dp[i][9] = dp[i - 1][8] % mod;
	}
	int res = 0;
	for (int i = 0; i < 10; res %= mod)
		res += dp[N - 1][i++];
	cout << res << '\n';
}