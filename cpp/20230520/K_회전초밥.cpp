#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, M, K, res[100'000];
vector<queue<int>> arr(200'001);

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> N >> M;
	int tmp;
	for (int i = 0; i < N; i++)
	{
		cin >> K;
		for (int j = 0; j < K; j++)
		{
			cin >> tmp;
			arr[tmp].push(i);
		}
	}

	int crr;
	for (int i = 0; i < M; i++)
	{
		cin >> tmp;
		if (!arr[tmp].empty())
		{
			res[arr[tmp].front()]++;
			arr[tmp].pop();
		}
	}
	for (int i = 0; i < N; i++)
		cout << res[i] << ' ';
}