#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int N, S, tmp, result = 0;
	cin >> N >> S;
	vector<int> arr(N + 1);
	arr[0] = 0;
	for (int i = 1; i <= N; i++)
	{
		cin >> tmp;
		arr[i] = arr[i - 1] + tmp;
	}
	for (int i = 1, j = 0; i <= N; i++)
	{
		while (1)
		{
			if (j == i)
				break;
			if (arr[i] - arr[j] >= S)
				result = result ? min(result, i - j) : i - j;
			else if (arr[i] - arr[j] < S)
				break;
			j++;
		}
	}
	cout << result << '\n';
}