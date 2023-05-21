#include <iostream>
#include <vector>
#include <bitset>
#include <cmath>
using namespace std;

int N;
vector<bitset<18>> map(18), crr(18);
int dy[] = {0, 1, -1, 0, 0}, dx[] = {0, 0, 0, 1, -1};

int main()
{
	cin >> N;
	int tmp;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> tmp;
			map[i][j] = tmp;
		}

	int ny, nx, res = 200'000, crr_res, flag;
	for (int i = 0; i < 1 << N; i++)
	{
		crr_res = 0;
		crr.assign(map.begin(), map.end());
		for (int j = 0; j < N; j++)
			if (i & (1 << j))
			{
				crr_res++;
				crr[0].flip(j);
				j + 1 < N ? crr[0].flip(j + 1) : 0;
				j - 1 >= 0 ? crr[0].flip(j - 1) : 0;
				crr[1].flip(j);
			}
		for (int j = 1; j < N; j++)
			for (int k = 0; k < N; k++)
				if (crr[j - 1][k])
				{
					crr_res++;
					for (int l = 0; l < 5; l++)
					{
						ny = j + dy[l];
						nx = k + dx[l];
						if (ny >= 0 && ny < N && nx >= 0 && nx < N)
							crr[ny].flip(nx);
					}
				}
		for (flag = 0; flag < N; flag++)
			if (crr[flag].any())
				break;
		if (flag == N)
			res = min(res, crr_res);
	}
	cout << (res == 200'000 ? -1 : res);
}