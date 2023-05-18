#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N, result;
vector<int> arr;

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	cin >> N;
	arr.resize(N);
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	for (int i = 0, tmp; i < N; i++)
	{
		cin >> tmp;
		arr[i] = tmp - arr[i];
	}

	int tmp_min, j, sign;
	for (int i = 0; i < N;)
	{
		if (!arr[i])
		{
			i++;
			continue;
		}
		sign = arr[i] > 0 ? 1 : -1;
		j = i + 1;
		tmp_min = arr[i] * sign;
		while (j < N && arr[i] * arr[j] > 0)
		{
			tmp_min = min(tmp_min, arr[j] * sign);
			j++;
		}
		
		for (int k = i; k < j; k++)
			arr[k] -= tmp_min * sign;
		result += tmp_min;
	}
	cout << result << '\n';
}