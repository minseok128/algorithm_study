#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int N;
	cin >> N;
	vector<pair<int, int>> arr(N);

	for (int i = 0; i < N; i++)
		cin >> arr[i].first >> arr[i].second;
	sort(arr.begin(), arr.end());
	
	vector<pair<int, int>> sarr;
	sarr.emplace_back(arr[0]);
	for (int i = 1, j = 1; i < N; i++)
	{
		if (sarr[j - 1].second >= arr[i].first)
		{
			if (sarr[j - 1].second < arr[i].second)
				sarr[j - 1].second = arr[i].second;
		}
		else
		{
			sarr.emplace_back(arr[i]);
			j++;
		}

	}

	long long res = 0;
	for (int i = 0; i < sarr.size(); i++)
		res += sarr[i].second - sarr[i].first;
	cout << res << '\n';
}