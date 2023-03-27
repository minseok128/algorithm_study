#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int h1, w1, h2, w2, total = 0;
	string s;

	cin >> h1 >> w1;
	vector<vector<int>> map1(h1, vector<int>(w1));
	for (int i = 0; i < h1; i++)
	{
		cin >> s;
		for (int j = 0; j < w1; j++)
		{
			if (s[j] == 'O')
			{
				map1[i][j] = 1;
				total++;
			}
			else
				map1[i][j] = 0;
		}
	}
	cin >> h2 >> w2;
	vector<vector<int>> map2(h2 + h1 * 2, vector<int>(w2 + w1 * 2, 0));
	for (int i = 0; i < h2; i++)
	{
		cin >> s;
		for (int j = 0; j < w2; j++)
		{
			if (s[j] == 'O')
				map2[h1 + i][w1 + j] = 1;
			else
				map2[h1 + i][w1 + j] = 0;
		}
	}

	int result = 0;
	for (int i = 0; i < h2 + h1; i++)
	{
		for (int j = 0; j < w2 + w1; j++)
		{
			int tmp = 0;
			for (int k = 0; k < h1; k++)
			{
				for (int l = 0; l < w1; l++)
				{
					if (map2[i + k][j + l] && map1[k][l])
						tmp++;
				}
			}
			result = max(result, tmp);
		}
	}

	cout << total - result << '\n';
}