#include <iostream>
#include <vector>
using namespace std;

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int N, M, tmp;
	cin >> N >> M;
	vector<int> arr(N + 1);
	arr[0] = 0;
	for (int i = 1; i <= N; i++)
	{
		cin >> tmp;
		arr[i] = arr[i - 1] + tmp;
	}
	for (int s, e; M > 0; M--)
	{
		cin >> s >> e;
		cout << arr[e] - arr[s - 1] << '\n';
	}
}