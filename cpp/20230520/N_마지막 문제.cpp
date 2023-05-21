#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
pair<long long, long long> v;
vector<long long> arr;
int main()
{
	cin >> N;
	arr.resize(N);

	for (int i = 0; i < N; i++)
		cin >> arr[i];
	v.second = 0;
	sort(arr.begin(), arr.end());
	for (int i = 0; i < N - 1; i++)
	{
		if (v.second < (arr[i + 1] - arr[i]) / 2)
			v = {arr[i], (arr[i + 1] - arr[i]) / 2};
	}
	if (v.second == 0)
		cout << "-1\n";
	else
		cout << v.first + v.second << '\n';
}