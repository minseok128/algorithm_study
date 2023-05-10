#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<pair<long long, long long>> arr;

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	long long people = 0, crr = 0;
	cin >> N;
	arr.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i].first >> arr[i].second;
		people += arr[i].second;
	}
	// people += people % 2;
	sort(arr.begin(), arr.end());
	for (int i = 0; i < N; i++)
	{
		crr += arr[i].second;
		if (crr >= (people + 1) / 2)
		{
			cout << arr[i].first << '\n';
			return (0);
		}
	}
}