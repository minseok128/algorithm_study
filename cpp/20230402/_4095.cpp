#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	while (1)
	{
		int n, m, result = 0;
		cin >> n >> m;
		if (!(n && m))
			return (0);
		vector<vector<int>> map(n + 1, vector<int>(m + 1, 0));
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				cin >> map[i][j];
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
			{
				if (map[i][j])
				{
					map[i][j] = min(min(map[i - 1][j], map[i][j - 1]), map[i - 1][j - 1]) + 1;
					result = max(result, map[i][j]);
				}
			}
		cout << result << '\n';
	}
}