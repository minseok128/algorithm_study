#include <iostream>
#include <vector>
#include <bitset>
#include <cmath>
using namespace std;

vector<bitset<10>> map(10), crr(10);
int dy[] = {0, 1, -1, 0, 0}, dx[] = {0, 0, 0, 1, -1};

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	char tmp;
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
		{
			cin >> tmp;
			if (tmp == '#')
				map[i][j] = 0;
			else
				map[i][j] = 1;
		}

	int ny, nx, res = 200'000, crr_res, flag;
	for (int i = 0; i < 1024; i++)
	{
		crr_res = 0;
		crr.assign(map.begin(), map.end());
		for (int j = 0; j < 10; j++)
			if (i & (1 << j))
			{
				crr_res++;
				crr[0].flip(j);
				j + 1 < 10 ? crr[0].flip(j + 1) : 0;
				j - 1 >= 0 ? crr[0].flip(j - 1) : 0;
				crr[1].flip(j);
			}
		for (int j = 1; j < 10; j++)
			for (int k = 0; k < 10; k++)
				if (crr[j - 1][k])
				{
					crr_res++;
					for (int l = 0; l < 5; l++)
					{
						ny = j + dy[l];
						nx = k + dx[l];
						if (ny >= 0 && ny < 10 && nx >= 0 && nx < 10)
							crr[ny].flip(nx);
					}
				}
		for (flag = 0; flag < 10; flag++)
			if (crr[flag].any())
				break;
		if (flag == 10)
			res = min(res, crr_res);
	}
	cout << (res == 200'000 ? -1 : res);
}