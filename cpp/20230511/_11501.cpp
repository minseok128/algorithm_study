#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[1000002];
long long addarr[1000002];

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	long long res, T, N, max, before;
	for(cin >> T; T > 0; T--)
	{
		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> arr[i];
		addarr[0] = arr[0];
		arr[N] = -1;
		for (int i = 1; i < N; i++)
			addarr[i] = addarr[i - 1] + arr[i];
		res = before = 0;
		max = arr[0];
		for (int i = 1; i <= N; i++)
		{
			if (arr[i] < arr[i - 1])
			{
				if (arr[i - 1] >= max)
				{
					res = arr[i - 1] * (i - 1) - addarr[i - 2];
					//cout << "res" << res << "\n";
					max = arr[i - 1];
					before = i;
				}
				else
				{
					//cout <<"i:" << i << "before:" << before<<'\n';
					res += arr[i - 1] * (i - before - 1) - addarr[i - 2] + addarr[before - 1];
					before = i;
				}
			}
		}
		cout << res << '\n';
	}
}