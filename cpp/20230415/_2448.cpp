#include <iostream>
#include <vector>
using namespace std;

int max_x, max_y;
vector<vector<char>> map; 

void recursive(int y, int x, int d)
{
	if (d == 3)
	{
		map[y][x] = '*';
		map[y + 1][x - 1] = map[y + 1][x + 1] = '*';
		for (int i = -2; i < 3; i++)
			map[y + 2][x + i] = '*';
		return ;
	}
	recursive(y, x, d / 2);
	recursive(y + d / 2, x - d / 2, d / 2);
	recursive(y + d / 2, x +  d / 2, d / 2);
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	cin >> max_y;
	max_x = 2 * max_y - 1;
	map = vector<vector<char>>(max_y + 1, vector<char>(max_x, ' '));
	recursive(1, max_x / 2, max_y);
	for (int i = 1; i <= max_y; i++)
	{
		for (int j = 0; j < max_x; j++)
			cout << map[i][j];
		cout << '\n';
	}
}