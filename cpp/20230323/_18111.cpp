#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, B, min_y = 0, max_y = 0, result_cost = 2137483647, result_y;
vector<vector<int>> map;

pair<int, int> get_cost(int s, int e)
{
	int cost = e - s;
	if (cost < 0)
		return (make_pair(cost * -2, cost));
	else
		return (make_pair(cost, cost));
}

int main()
{
	cin >> N >> M >> B;
	map = vector<vector<int>>(N, vector<int>(M));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
			min_y = min(min_y, map[i][j]);
			max_y = max(max_y, map[i][j]);
		}
	}
	for (int y = min_y; y <= max_y; y++)
	{
		pair<int, int> cost = make_pair(0, 0);
		pair<int, int> tmp;
		for (int i = 0; i < N ; i++)
		{
			for (int j = 0; j < M; j++)
			{
				tmp = get_cost(map[i][j], y);
				cost.first += tmp.first;
				cost.second += tmp.second;
			}
		}
		if (cost.second <= B)
		{
			if (cost.first <= result_cost)
			{
				result_cost = cost.first;
				result_y = y;
			}
		}
	}
	cout << result_cost << " " << result_y << '\n';

}