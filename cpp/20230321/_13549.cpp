#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> map;
int N, K, max_x, result = 2147483647;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	cin >> N >> K;
	max_x = max(N, K) * 2 + 1;
	map = vector<int>(max_x);
	if (K <= N)
	{
		cout << N - K << '\n';
		return (0);
	}

	queue<int> q;
	q.push (N);
	
	while (!q.empty())
	{
		int crr = q.front();
		q.pop();

		for (int k = 0; k < 3; k++)
		{
			int new_x = (k == 0) ? crr * 2 : ((k == 1) ? crr - 1 : crr + 1);
			int dt = k == 0 ? 0 : 1;
			if (new_x >= 0 && new_x < max_x && new_x != N)
			{
				if (new_x == K && min(result, map[crr] + dt) != result)
				{
					result = map[crr] + dt;
				}
				else if (map[crr] + dt < map[new_x] || map[new_x] == 0)
				{
					map[new_x] = map[crr] + dt;
					q.push(new_x);
				}
			}
		}
	}
	cout << result << '\n'; 
}
