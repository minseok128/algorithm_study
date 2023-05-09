#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int N, L, x1, x2, r = -1, res = 0;
	cin >> N >> L;
	vector<pair<int, int>> arr(N);

	for (int i = 0; i < N; i++)
		cin >> arr[i].first >> arr[i].second;
	sort(arr.begin(), arr.end());

	for (int i = 0; i < N; i++)
	{
		x1 = arr[i].first;
		x2 = arr[i].second;
		if (r >= x2 - 1)
			continue;
		if (r >= x1)
			x1 = r + 1;
		res += (x2 - x1) / L + 1;
		if ((x2 - x1) % L == 0)
		{
			res -= 1;
			r = x2 - 1;
		}
		else
			r = x2 - 1 + L - (x2 - x1) % L;
	}
	cout << res << '\n';
}