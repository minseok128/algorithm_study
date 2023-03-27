#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int N, K;
	cin >> N >> K;

	int a, b, c;
	vector<vector<int>> arr(3, vector<int>(N));
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b >> c;
		arr[0][i] = a + b;
		arr[1][i] = b + c;
		arr[2][i] = c + a;
	}
	sort(arr[0].begin(), arr[0].end(), greater<>());
	sort(arr[1].begin(), arr[1].end(), greater<>());
	sort(arr[2].begin(), arr[2].end(), greater<>());


	int ab = 0, bc = 0, ca = 0;
	for (int i = 0; i < K; i++)
	{
		ab += arr[0][i];
		bc += arr[1][i];
		ca += arr[2][i];
	}

	cout << max(ab, max(bc, ca)) << '\n';
}