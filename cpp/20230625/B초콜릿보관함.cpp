#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int T;
	for (cin >> T; T; T--)
	{
		char map[3][3];

		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				cin >> map[i][j];

		int arr[8];
		arr[0] = map[0][0];
		arr[1] = map[0][1];
		arr[2] = map[0][2];
		arr[3] = map[1][2];
		arr[4] = map[2][2];
		arr[5] = map[2][1];
		arr[6] = map[2][0];
		arr[7] = map[1][0];

		int cnt = 0;
		int info[4] = {0};
		for (int i = 0; i < 8; i++)
		{
			int l = i != 0 ? i - 1 : 7;
			int r = (i + 1) % 8;
			if (arr[i] == 'O')
			{
				if (arr[l] != 'X' && arr[l] != 'O')
					arr[i] = arr[l];
				else if (arr[r] != 'X' && arr[r] != 'O')
					arr[i] = arr[r];
				else
					arr[i] = cnt++;

				if (arr[l] == 'O')
				{
					info[arr[i]]++;
					arr[l] = arr[i];
				}
				if (arr[r] == 'O')
				{
					info[arr[i]]++;
					arr[r] = arr[i];
				}
				info[arr[i]]++;
			}
		}

		int res[8] = {0};
		for (int i = 0; i < 4; i++)
		{
			//cout << info[i] << ' ';
			res[info[i]]++;
		}
		//cout << '\n';

		int k;
		cin >> k;
		for (int i = 0; i < k; i++)
		{
			int a;
			cin >> a;
			res[a]--;
		}

		int i;
		for (i = 1; i < 8; i++)
		{
			//cout << res[i] << ' ';
			if (res[i] != 0)
				break ;
		}
		cout << ((i == 8) ? '1' : '0') << '\n';
	}
}