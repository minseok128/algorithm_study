#include <iostream>
#include <vector>
using namespace std;

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	int N, K, tmp, x1, y1, x2, y2;
	cin >> N >> K;
	vector<vector<int>> arr(N + 1, vector<int>(N + 1, 0));
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			cin >> tmp;
			arr[i][j] = tmp + arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
		}
	// cout << '\n';
	//  for (int i = 0; i <= N; i++)
	//{
	//	for (int j = 0; j <= N; j++)
	//		cout << arr[i][j] << ' ';
	//	cout << '\n';
	//  }
	for (int i = 0; i < K; i++)
	{
		cin >> y1 >> x1 >> y2 >> x2;
		// cout << arr[y2][x2] << "-" << arr[y2][x1 - 1] << "-" << arr[y1 - 1][x2] << "+" << arr[y1 - 1][x1 - 1] << '\n';
		cout << arr[y2][x2] - arr[y2][x1 - 1] - arr[y1 - 1][x2] + arr[y1 - 1][x1 - 1] << '\n';
	}
}