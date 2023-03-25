#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int map[500001][4];
int N, K, max_x = 500001, result = 1;

int sigma(int n)
{
	return ((n) * (n + 1) / 2);
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	cin >> N >> K;

	if (N == K)
	{
		cout << "0\n";
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
			int new_x = (k == 0) ? crr - 1 : ((k == 1) ? crr + 1 : crr * 2);
			int new_K = K + sigma(map[crr][0] + 1);
			if (new_x >= 0 && new_x < max_x && new_x != N)
			{
				if (map[new_K][0] != 0 || new_K == N)
				{
					if (new_K != max_x)
					{
						cout << "map[new_K]:" << map[new_K][2] << " || map[crr][0]:" << map[crr][0] << " || K:" << new_K << '\n';
						if ((map[crr][0] + 1) % 2 == 1 && map[new_K][2] != 0)
						{
							cout << map[crr][0] + 1 << '\n';
							return (0);
						}
						if ((map[crr][0] + 1) % 2 == 0 && (map[new_K][1] != 0 || new_K == N))
						{
							cout << map[crr][0] + 1 << '\n';
							return (0);
						}
					}
				}
				if (new_K > max_x)
				{
					cout << "-1\n";
					return (0);
				}
				if (new_x == new_K)
				{
					cout << "here" << map[crr][0] + 1 << '\n';
					return (0);
				}
				//else if (map[crr][0] + 1 <= map[new_x][0] || map[new_x][0] == 0)
				//else if(map[new_x][3] < 5)
				//{
					//cout << "new_x:" << new_x << " || K:" << new_K << '\n';
				if (map[new_x][3] < 10)
				{
					if (map[new_x][3] == 0)
						map[new_x][0] = map[crr][0] + 1;
					map[new_x][3]++;
					q.push(new_x);
					map[new_x][map[new_x][0] % 2 + 1] = 1;
				}
			}
		}
	}
}
