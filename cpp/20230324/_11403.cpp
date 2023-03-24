#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	
	cin >> N;
	vector<vector<int>> roads(N, vector<int>(N, 0));
	vector<vector<int>> result(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> roads[i][j];
	}
	queue<int> q;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (roads[i][j] == 1)
			{
				q.push(j);

				while (!q.empty())
				{
					int crr = q.front();
					q.pop();
					result[i][crr] = 1;
					
					for (int k = 0; k < N; k++)
					{
						if (roads[crr][k] && result[i][k] == 0)
						{
							q.push(k);
						}
					}
				}
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%d ", result[i][j]);
		}
		printf("\n");
	}
}